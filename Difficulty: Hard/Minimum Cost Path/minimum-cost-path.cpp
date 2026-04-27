class Solution {
public:
    bool isSafe(int newX, int newY, int m, int n) {
        return (newX >= 0 && newX < m && newY >= 0 && newY < n);
    }

    int minimumCostPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Up, Down, Left, Right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Track distances and visited cells in 2D arrays directly mapped to the grid
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        
        // The set will store {weight, {x_coordinate, y_coordinate}}
        set<pair<int, pair<int, int>>> st;

        // Initialize starting node
        dist[0][0] = grid[0][0];
        st.insert({grid[0][0], {0, 0}});

        // Process until empty
        while (!st.empty()) {
            auto frontPair = *st.begin();
            int wt = frontPair.first;
            int x = frontPair.second.first;
            int y = frontPair.second.second;
            
            st.erase(st.begin());

            // Skip if we have already finalized this cell
            if (isVisited[x][y]) {
                continue;
            }
            isVisited[x][y] = true;

            // Explore the 4 valid neighbors
            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (isSafe(newX, newY, m, n) && !isVisited[newX][newY]) {
                    int nbrWeight = grid[newX][newY];
                    
                    if (dist[x][y] + nbrWeight < dist[newX][newY]) {
                        // If it was already found and has a higher distance, remove it from the set
                        if (dist[newX][newY] != INT_MAX) {
                            st.erase({dist[newX][newY], {newX, newY}});
                        }
                        
                        // Update distance and insert into the set
                        dist[newX][newY] = dist[x][y] + nbrWeight;
                        st.insert({dist[newX][newY], {newX, newY}});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};