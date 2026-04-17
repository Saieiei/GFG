class Solution {
  public:
  
    bool isCycleDFS(int i, vector<int>& isVisited, vector<int>&isPathVisited, vector<vector<int>>& adjList){
        //mark it as visited
        isVisited[i] = true;
        isPathVisited[i] = true;
        
        //explore nbrs
        for(int nbr: adjList[i]){
            if(!isVisited[nbr]){
                if(isCycleDFS(nbr, isVisited, isPathVisited, adjList)){
                    return true;
                }
            }
            else if(isPathVisited[nbr] == true){
                return true;
            }
        }
        isPathVisited[i] = false;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        //adjList
        vector<vector<int>> adjList(V);
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            //directed u->v
            adjList[u].push_back(v);
        }
        
        vector<int> isVisited(V, false);
        vector<int> isPathVisited(V, false);
        
        //disconnected graph
        for(int i=0; i<V; i++){
            if(!isVisited[i]){
                if(isCycleDFS(i, isVisited, isPathVisited, adjList)){
                    return true;
                }
            }
        }
        return false;
    }
};