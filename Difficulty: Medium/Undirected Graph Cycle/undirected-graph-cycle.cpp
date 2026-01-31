class Solution {
  public:
    bool FindCycleDFS(int src, unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& visited, int& parent){
        visited[src] = 1;
        for(int nbr: adjList[src]){
            if(!visited[nbr]){
                bool ans = FindCycleDFS(nbr, adjList, visited, src);
                if(ans == true) return true; //cycle found
            }
            else{//already visited, then check if it was a parent or not
                if(nbr != parent) return true; //found cycle
            }
        }
        return false; //didnt find cycle
    }
    bool isCycleHelper(unordered_map<int, vector<int>>& adjList, int& V){
        //initial state
        //queue<int>q;
        unordered_map<int, bool>visited;
        int parent = -1;
        //multiple component.
        for(int src = 0; src < V; src++){
            if(!visited[src]){
                bool ans = FindCycleDFS(src, adjList, visited, parent);
                if(ans == true) return ans;//cycle found and returning
            }
        }
        return false;// no cycle
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
        
        return isCycleHelper(adjList, V);
    }
};