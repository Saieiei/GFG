//we will have to keep the track of the recursion path and visited or not
class Solution {
  public:
    bool isCyclicDFS(int src, unordered_map<int, bool>& visted, unordered_map<int, bool>& DFSTracker, unordered_map<int, vector<int>>& adjList){
        visted[src] = true;
        DFSTracker[src] = true;
        for(int nbr: adjList[src]){
            if(!visted[nbr]){
                bool ans = isCyclicDFS(nbr, visted, DFSTracker, adjList);
                if(ans == true) return true;
            }
            else{//visited but check if same dfs path is same using the tracker
                if(DFSTracker[nbr] == true) return true;
            }
        }
        //backtracking
        DFSTracker[src] = false;
        return false;
    }
    bool isCyclicHelper(int V, unordered_map<int, vector<int>>& adjList){
        unordered_map<int, bool> visted;
        unordered_map<int, bool> DFSTracker;
        //it can have discontinued components
        for(int src=0; src < V; src++){
            if(!visted[src]){
                bool ans = isCyclicDFS(src, visted, DFSTracker, adjList);
                if(ans == true) return true; //cycle found means return there only
            }
        }
        return false; //no cycle
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        //1st create adjList
        unordered_map<int, vector<int>>adjList;
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            //since its directed only u->v
            adjList[u].push_back(v);
        }
        
        return isCyclicHelper(V, adjList);
        
    }
};