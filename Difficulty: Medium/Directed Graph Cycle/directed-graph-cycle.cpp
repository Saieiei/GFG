class Solution {
  public:
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> indegree(V);
        //adjList
        vector<vector<int>> adjList(V);
        for(vector<int>& edge: edges){
            int u = edge[0];
            int v = edge[1];
            //directed
            //u->v
            adjList[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(int nbr: adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        return (ans.size() == V) ? false : true;
    
    }
};