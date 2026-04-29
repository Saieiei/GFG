//MST -> pprims algo
class Solution {
  public:
    int getMinWtIndex(vector<int>& dist, vector<bool>& isVisited, const int V){
        int index = -1;
        int wt = INT_MAX;
        for(int i=0; i<V; i++){
            if(isVisited[i] == false){
                if(dist[i] < wt){
                    wt = dist[i];
                    index = i;
                }
            }
        }
        return index;
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        //create adjList 1st
        vector<vector<pair<int, int>>> adjList(V);
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            //bidirectional
            adjList[u].push_back({w, v}); // u w v
            adjList[v].push_back({w, u});
        }
        
        //create markers for prims algo
        vector<bool> isVisited(V, false);
        vector<int> dist(V, INT_MAX);
        vector<int> parents(V, -1);
        //isVisited[0] = true;
        dist[0] = 0;
        
        //start the process
        while(true){
            int u =  getMinWtIndex(dist, isVisited, V);
            if(u == -1){
                break;
            }
            //just mark it as visited
            isVisited[u] = true;
            //explore its nbrs
            for(pair<int, int> nbr: adjList[u]){
                int w = nbr.first;
                int v = nbr.second;
                //check if already visisted
                if(isVisited[v] == false){
                    //check the wts
                    if(w < dist[v]){
                        //in that case update wts and parents
                        //and mark it as visited
                        dist[v] = w;
                        parents[v] = u;
                        //isVisited[v] = true;
                    }
                }
            }
        }
        //return the sum
        int ans = 0;
        for(int i=0; i<V; i++){
            ans += dist[i];
        }
        return ans;
        
    }
};