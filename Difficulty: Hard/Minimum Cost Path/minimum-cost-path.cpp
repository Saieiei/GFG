class Solution
{
    public:
    bool isSafe(int& newX, int& newY, int& n){
        if((newX >=0 && newX < n) && (newY >=0 && newY < n)){
            return true;
        }
        return false;
    }

    //this will be too much take in
    //1st is to create a adjList
    //the adjList will be created with the help of nodeIDs
    //this will help us track 1d dist[]
    //we will have to convert the matrix into adjList
    //in the process of convertion we will explore the matrix
    //up, down, left right
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        //up down left right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        //dont have to find m cuz its a square grid
        vector<vector<pair<int, int>>> adjList(n*n);
        //traverse through the matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int uNodeID = i*n+j;
                //explore the nbrs
                //4 sides
                for(int k=0; k<4; k++){
                    //coordinates of the new node
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    if(isSafe(newX, newY, n)){
                        int nbrNodeID = newX*n+newY;
                        int nbrWeight = grid[newX][newY];
                        adjList[uNodeID].push_back({nbrWeight, nbrNodeID});
                    }
                }
            }
        }
        
        //2nd part is to do the dijstras algo
        //set
        vector<int> dist(n*n, INT_MAX);
        set<pair<int, int>> st;
        int startingNodeID = 0; //(i*n+j)
        st.insert({grid[0][0], startingNodeID});
        dist[startingNodeID] = grid[0][0];
        int lastNodeID = (n-1)*n + (n-1);
        
        //process until empty
        while(!st.empty()){
            pair<int, int> frontPair = *st.begin();
            int wt = frontPair.first;
            int node = frontPair.second;
            st.erase(st.begin());
            
            //optimization else TLE
                if(node == lastNodeID) return wt;
            
            //process nbrs
            for(const pair<int, int>& nbr: adjList[node]){
                int nbrWt = nbr.first;
                int nbrNode = nbr.second;
                if(dist[node] + nbrWt < dist[nbrNode]){
                    //update dist and push
                    //and also delete if found in the st
                    //we forget this step (optimized)
                    if(dist[nbrNode] != INT_MAX){
                        //found it in the st
                        st.erase({dist[nbrNode], nbrNode});
                    }
                    dist[nbrNode] = dist[node] + nbrWt;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        
        return dist[lastNodeID];
    }
};