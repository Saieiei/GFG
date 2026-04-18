//BFS
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V);
        //adjList
        vector<vector<int>> adjList(V);
        for(const vector<int>& edge: edges){
            int u = edge[0];
            int v = edge[1];
            //u->v
            adjList[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        //initial process
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        //process q
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            //explore the nbrs
            for(int nbr: adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};