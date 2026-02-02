//1st create AdjList
//2nd create and keep track of indegrees
//3rd keep performing until the q is empty

class Solution {
  public:
    void solveBFS(int& V, vector<vector<int>>& edges, unordered_map<int, vector<int>>& AdjList, vector<int>& ans){
        //2nd create and keep track of indegrees
        unordered_map<int, int> Indegrees;
        //initialise all the indegrees to 0
        for(int i = 0; i < V; i++){
            Indegrees[i] = 0;
        }
        //track indegrees of each node
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            //u->v, v will be tracked for the indegrees
            Indegrees[v]++;
        }
        //push the 0 indegree inside the q
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(Indegrees[i] == 0){
                q.push(i);
            }
        }
        //keep on executing until q is empty
        while(!q.empty()){
            int frontEle = q.front();
            q.pop();
            ans.push_back(frontEle);
            //update the indegree
            for(int nbr: AdjList[frontEle]){
                Indegrees[nbr]--;
                if(Indegrees[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //1st create AdjList
        unordered_map<int, vector<int>> AdjList;
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            //u->v (directed)
            AdjList[u].push_back(v);
        }
        //lets start the process now
        vector<int> ans;
        solveBFS(V, edges, AdjList, ans);
        return ans;
        
    }
};