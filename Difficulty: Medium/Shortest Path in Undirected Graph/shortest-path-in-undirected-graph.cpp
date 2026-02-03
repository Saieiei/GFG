#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {
        // 1. Create Adjacency List
        vector<vector<int>> adjList(V);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u); 
        }

        // 2. Create Distance Array (Initialize with -1)
        // This acts as both the 'visited' array and the 'answer' array
        vector<int> dist(V, -1);
        
        // 3. Queue for BFS
        queue<int> q;

        // 4. Initial State
        q.push(src);
        dist[src] = 0; // Distance from source to source is 0

        // 5. Standard BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nbr : adjList[node]){
                // If the neighbor has not been visited (dist is still -1)
                if(dist[nbr] == -1){
                    dist[nbr] = dist[node] + 1; // Distance is parent's dist + 1
                    q.push(nbr);
                }
            }
        }

        return dist;
    }
};