class Solution {
  public:
  
    bool dfs(int i, int parent, unordered_map<int, vector<int>>& adjList, vector<bool>& isVisited){
        isVisited[i] = true;
        //explore nbrs
        for(int nbr: adjList[i]){
            if(!isVisited[nbr]){
                if(dfs(nbr, i, adjList, isVisited)){
                    //cycle is detected
                    return true;
                }
            }
            else if(nbr != parent){
                return true;
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        bool ans = false;
        int parent = -1;
        vector<bool> isVisited(V, false);
        
        unordered_map<int, vector<int>>adjList;
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
        }
        
        //discontinuous graph
        for(int i=0; i<V; i++){
            if(!isVisited[i]){
                if(dfs(i, parent, adjList, isVisited)){
                    return true;
                }
                
            }
        }
        return false;
        
    }
};