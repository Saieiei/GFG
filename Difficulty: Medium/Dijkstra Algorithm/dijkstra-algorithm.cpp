//set method
//O(v + u (log v))
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //adjList
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            //undirected
            //u<->v
            adjList[u].push_back({w, v});
            adjList[v].push_back({w, u});
        }
        
        set<pair<int, int>> st; //w, u
        st.insert({0, src});
        vector<int> distAns(V, INT_MAX);
        distAns[src] = 0;
        
        //
        while(!st.empty()){
            pair<int, int> frontPair = *st.begin();
            st.erase(*st.begin());
            int Node = frontPair.second;
            int NodeWt = frontPair.first;
            //explore its nbrs, if the wt is less in dist then 
            //it will be taken care of by removing it from st
            //and not processing it from the next next part
            for(pair<int, int> nbr: adjList[Node]){
                int nbrNode = nbr.second;
                int nbrWt = nbr.first;
                if(distAns[Node] + nbrWt < distAns[nbrNode]){
                    //remove if the bigger 1 is found in the st
                    auto it = st.find({distAns[nbrNode], nbrNode});
                    if(it != st.end()){//found it
                        st.erase(it);
                    }
                    //normal part, where u update the distAns[]
                    //and push the updated pair in the st, to keep the loop going
                    distAns[nbrNode] = distAns[Node] + nbrWt;
                    st.insert({distAns[nbrNode], nbrNode});
                }
            }
        }
        return distAns;
    }
};