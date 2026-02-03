class Solution {
  public:
    // Helper function for Topological Sort
    void findTopoSort(int node, vector<pair<int,int>> adj[], vector<int> &visited, stack<int> &st) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!visited[v]) {
                findTopoSort(v, adj, visited, st);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // 1. Build Weighted Adjacency List
        // Note: The problem input edges are usually [u, v, weight]
        vector<pair<int, int>> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // 2. Topological Sort (using DFS)
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                findTopoSort(i, adj, visited, st);
            }
        }

        // 3. Initialize Distances
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Source is always 0 in this problem

        // 4. Process nodes in Topological Order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // Only relax edges if the current node has been reached
            if (dist[node] != INT_MAX) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int w = it.second;
                    
                    if (dist[node] + w < dist[v]) {
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }

        // 5. Handle unreachable nodes (convert INT_MAX to -1)
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};