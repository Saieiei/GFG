//we require set and dis[] and adjList
//easy only
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //create adjList
        unordered_map<int, vector<pair<int, int>>> adjList; //u, w, v
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            //undirected
            adjList[u].push_back({w, v});
            adjList[v].push_back({w, u});
        }
        set<pair<int, int>> st; //w, u
        vector<int>dist (V, INT_MAX);
        //initial case
        dist[src] = 0;
        st.insert({0, src});
        //start the process
        while(!st.empty()){
            pair<int, int> frontPair =  *(st.begin());
            //w, u
            int nodeDist = frontPair.first;
            int node = frontPair.second;
            //after u take element from the set pop it
            st.erase(st.begin());
            //process its nbrs
            for(pair<int, int> nbr: adjList[node]){
                int nbrDist = nbr.first;
                int nbrNode = nbr.second;
                //check if smaller in dist vector
                if(dist[node] + nbrDist < dist[nbrNode]){
                    //we will delete nbrs occurance if found and update and insert it back in st
                    auto result = st.find({dist[nbrNode], nbrNode});
                    if(result != st.end()){
                        //found it and pop it
                        st.erase(result);
                    }
                    //update the dist and push the pair in st 
                    dist[nbrNode] = dist[node] + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        return dist;
        
        
    }
};