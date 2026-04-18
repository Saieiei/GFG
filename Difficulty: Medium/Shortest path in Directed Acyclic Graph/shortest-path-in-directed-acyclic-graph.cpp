class Solution {
  public:

    //we push in the reversed order
    void dfsHelper(int i, stack<int>& st, vector<vector<pair<int, int>>>& adjList, vector<bool>& isVisited){
        isVisited[i] = true;
        for(const pair<int, int>& nbr: adjList[i]){
            int v = nbr.first;
            if(!isVisited[v]){
                dfsHelper(v, st, adjList, isVisited);
            }
        }
        st.push(i);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int, int>>> adjList(V);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            //directed
            //u->v
            adjList[u].push_back({v, w});
        }
        stack<int> st;
        vector<bool> isVisited(V, false);
        
        //disconnected graph
        for(int i=0; i<V; i++){
            if(!isVisited[i]){
                dfsHelper(i, st, adjList, isVisited);
            }
        }
        
        vector<int> distAns(V, INT_MAX);
        distAns[0] = 0;
        
        while(!st.empty()){
            int topNode = st.top();
            st.pop();
            
            //dont need to increase INT-MAX/unreachable nodes
            if(distAns[topNode] != INT_MAX){ //starting -> distAns[0] = 0 ✔️
                //explore nbrs
                for(const pair<int, int>& nbr: adjList[topNode]){
                    int nbrV = nbr.first;
                    int nbrW = nbr.second;
                    //update
                    if(distAns[topNode] + nbrW < distAns[nbrV]){
                        distAns[nbrV] = distAns[topNode] + nbrW;
                    }
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(distAns[i] == INT_MAX){
                distAns[i] = -1;
            }
        }
        return distAns;
    }
};