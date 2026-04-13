//BFS
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;
        vector<bool> isVisisted(100000, false);
        int steps = 0;
        q.push({start, steps});
        isVisisted[start] == true;
        const int mod = 100000;
        
        while(!q.empty()){
            pair<int, int> frontEles = q.front();
            q.pop();
            int node = frontEles.first;
            int steps = frontEles.second;
            //check
            if(node == end){
                return steps;
            }
            //if not explore nbrs/multiplications
            for(int mulValues: arr){
                int mulValueNodes = (node * mulValues) % mod;
                int newStepValue = steps + 1;
                //push in node if not visited and mark them as visited immediately
                if(!isVisisted[mulValueNodes]){
                    isVisisted[mulValueNodes] = true;
                    q.push({mulValueNodes, newStepValue});
                }
            }
            
        }
        //not possible
        return  -1;
        
    }
};
