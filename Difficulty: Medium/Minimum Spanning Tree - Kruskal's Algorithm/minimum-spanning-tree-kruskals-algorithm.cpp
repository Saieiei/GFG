//kruskals algo
//findParent
//findUnion
class Solution {
  public:
    int findParent(int node, vector<int>& parents){
        //check if self parent
        if(parents[node] == node){
            return node;
        }
        //do path compression else
        return parents[node] = findParent(parents[node], parents);
    }
    void findUnion(int uParent, int vParent, vector<int>& ranks, vector<int>& parents){
        int uRank = ranks[uParent];
        int vRank = ranks[vParent];
        if(uRank >= vRank){
            ranks[uParent]++;
            parents[vParent] = uParent;
        }
        else{
            ranks[vParent]++;
            parents[uParent] = vParent;
        }
    }
    static bool mycmp(vector<int>& a, vector<int>& b){
        //0->u, 1->v, 2->w
        return (a[2]<b[2]);  
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        //isVisited is not required
        //no parents required
        //no adjList required
        
        //trackers
        int ans =0;
        vector<int> parents(V);
        vector<int> ranks(V, 0); //not -1
        //self parents
        for(int i=0; i<V; i++){
            parents[i] = i;
        }
        
        //sort them in ascending order
        sort(edges.begin(), edges.end(), mycmp);
        
        //start the process
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            //find parents
            int uParent = findParent(u, parents);
            int vParent = findParent(v, parents);
            
            //union
            if(uParent != vParent){
                findUnion(uParent, vParent, ranks, parents);
                ans += w;
            }
        }
        return ans;
        
    }
};