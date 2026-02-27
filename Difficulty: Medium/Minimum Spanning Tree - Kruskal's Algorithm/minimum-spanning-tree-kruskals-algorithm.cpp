//we need to have 2 vectores, parents and ranks
//initialise all parents to itself and the all the ranks to 0
//we need 2 functions, 1 to find parent another to do union
//for the processing we need to arerange them based on increasing weights
//for this we need to have a custom mycmp function
//we will only do the processing when the parents are not the same
//to find the parent, if th eparent is itself then return
//if not them keep recursion and save it directly (path compression)
//if the Uparent rank is less then the Vparent then Vparent is the parent of Uparent
//Vparents rank will increase by 1
//viceversa


class Solution {
  public:
  static bool mycmp(vector<int>& a, vector<int>& b){
      return (a[2] < b[2]);
  }
    int findParent(int node, vector<int>& parents){
        if(parents[node] == node){
            return node;
        }
        //path compression
        return parents[node] = findParent(parents[node], parents);
    }
    void unionSet(int uParent, int vParent, vector<int>& parents, vector<int>& ranks){
        if(ranks[uParent] < ranks[vParent]){
            parents[uParent] = vParent;
            ranks[vParent]++;
        }
        else{
            parents[vParent] = uParent;
            ranks[uParent]++;
        }
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        //sort the edges 1st
        sort(edges.begin(), edges.end(), mycmp);
        
        vector<int> parents(V);
        for(int u=0; u <V; u++){
            parents[u] = u;
        }
        vector<int> ranks(V, 0);
        int ans = 0;
        
        //start processing
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            int uParent = findParent(u, parents);
            int vParent = findParent(v, parents);
            //process only when the parents r not the same
            if(uParent != vParent){
                unionSet(uParent, vParent, parents, ranks);
                ans += w; 
            }
        }    
        return ans;
    }
};