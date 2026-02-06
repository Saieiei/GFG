//

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const long long INF = 1e8;
        //create adjList
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            //directed edges
            adjList[u].push_back({w, v});
        }
        
        //initialise
        vector<int>dist(V, INF);
        dist[src] = 0;
        
        //loop for i<n-1 times to get the shortest path
        for(int i = 0; i < V - 1; i++){
            for(pair<const int, vector<pair<int, int>>> a: adjList){ 
                int node = a.first; //nbr = a.second 
                for(pair<int, int> nbr: a.second){
                    int nbrDist = nbr.first;
                    int nbrNode = nbr.second;
                    if(dist[node] != INF && dist[node] + nbrDist < dist[nbrNode]){
                        dist[nbrNode] = dist[node] + nbrDist;
                    }
                }
            }
        }
        
        //do 1 last iteration to find cycle
        bool negativeCycle = false;
        for(int i = 0; i < V - 1; i++){
            for(pair<const int, vector<pair<int, int>>> a: adjList){
                int node = a.first; //nbr = a.second
                for(pair<int, int> nbr: a.second){
                    int nbrDist = nbr.first;
                    int nbrNode = nbr.second;
                    if(dist[node] != INF && dist[node] + nbrDist < dist[nbrNode]){
                        negativeCycle = true;
                        return {-1};
                    }
                }
            }
        }
        
        return dist;
        
    }
};
