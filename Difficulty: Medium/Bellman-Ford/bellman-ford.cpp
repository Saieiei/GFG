// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> distAns(V, 1e8);
        distAns[src] = 0;
        
        //adjList
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            //directed
            //u->v
            adjList[u].push_back({w, v});
        }
        
        //iterate V-1 times
        for(int i=0; i<V-1; i++){
            //traverse through the adjList
            for(pair<const int, vector<pair<int, int>>> a: adjList){
                int u = a.first;
                if(distAns[u] == 1e8){
                    continue;
                }
                vector<pair<int, int>> data = a.second;
                //explore the nbrs
                for(pair<int, int> pairData: data){
                    int nbrWt = pairData.first;
                    int nbrNode = pairData.second;
                    if(distAns[u] + nbrWt < distAns[nbrNode]){
                        distAns[nbrNode] = distAns[u] + nbrWt;
                    }
                }
            }
        }
        
        //iterate 1 last time to check if there is a - loop
        do{
            //traverse through the adjList
            for(pair<const int, vector<pair<int, int>>> a: adjList){
                int u = a.first;
                if(distAns[u] == 1e8){
                    continue;
                }
                vector<pair<int, int>> data = a.second;
                //explore the nbrs
                for(pair<int, int> pairData: data){
                    int nbrWt = pairData.first;
                    int nbrNode = pairData.second;
                    if(distAns[u] + nbrWt < distAns[nbrNode]){
                        //- loop, not possible to find shortest path
                        return {-1};
                    }
                }
            }
        }while(false);
        
        return distAns;
        
    }
};
