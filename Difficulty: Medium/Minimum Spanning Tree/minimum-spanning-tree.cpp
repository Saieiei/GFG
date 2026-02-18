class Solution
{
public:
    int getMinValueNode(vector<int>& key, vector<int>& mst) {
        int temp = INT_MAX;
        int index = -1; // rep. actual node having min value
        for(int i = 0; i < key.size(); ++i) {
            if(key[i] < temp && mst[i] == false) {
                temp = key[i];
                index = i;
            }
        }
        return index;
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        // Build the adjacency list internally
        vector<vector<int>> adj[V]; 
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        // Prim's algorithm
        vector<int> key(V, INT_MAX);
        vector<int> mst(V, false); // to keep track which all nodes are added into mst.
        vector<int> parent(V, -1); // stores final mst relation.

        key[0] = 0;

        while(true) {
            // Step 1: Get the node with the minimum key value
            int u = getMinValueNode(key, mst);
            
            // If all reachable nodes are visited, getMinValueNode returns -1
            if(u == -1) break;

            // Step 2: Mark the picked node as included in MST
            mst[u] = true;

            // Step 3: Process all adjacent nodes to u
            for(auto edge : adj[u]) {
                int v = edge[0];
                int w = edge[1];
                
                // If v is not in MST and weight of (u,v) is smaller than current key of v
                if(mst[v] == false && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        
        // Calculate the sum of weights of edges in the Minimum Spanning Tree
        int sum = 0;
        for(int i = 0; i < V; i++) {
            sum += key[i];
        }
        
        return sum;
    }
};