class Solution {
  public:
    bool FindCycleBFS(int& src, unordered_map<int, vector<int>>& adjList, queue<int>& q, unordered_map<int, bool>& visited, unordered_map<int, int>& parents){
        //intial state
        q.push(src);
        visited[src] = 1;
        parents[src] = -1;
        
        //keep doing it untill ur q is empty
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(int nbr: adjList[frontNode]){
                if(!visited[nbr]){//not visited
                    visited[nbr] = 1;
                    q.push(nbr);
                    parents[nbr] = frontNode;
                }
                else{ //its visited
                    if(parents[frontNode] != nbr)
                    return true; //cycle found
                    
                }
            }
        }//no cycle found
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        //since its undirected
        //u->v and v->u
        //create adjList
        unordered_map<int, vector<int>>adjList;
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
        }
        
        queue<int>q;
        unordered_map<int, bool>visited;
        unordered_map<int, int>parents;

        //multiple component.
        for(int src = 0; src < V; src++){
            if(!visited[src]){
                bool ans = FindCycleBFS(src, adjList, q, visited, parents);
                if(ans == true) return ans;//cycle found and returning
            }
        }
        return false;// no cycle
    }
};