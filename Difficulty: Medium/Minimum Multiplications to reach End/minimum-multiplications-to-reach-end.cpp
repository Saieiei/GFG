//BFS
class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        //bc
        if(start == end){
            return 0;
        }
        //no need of adjList
        const int module = 1000;
        //we cant predict this, but its suppose to be high
        vector<bool> isVisited(100000, false);
        int steps = 0;
        
        //BFS
        queue<pair<int, int>> q;
        q.push({start, steps});
        isVisited[start] = true;
        
        //start the process
        while(!q.empty()){
            pair<int, int> frontPair = q.front();
            q.pop();
            int frontNumber = frontPair.first;
            int frontSteps = frontPair.second;
            //explore nbrs
            for(int multiplierNbr : arr){
                int nbrValue = (multiplierNbr * frontNumber) % module;
                //check if this is already visisted
                if(!isVisited[nbrValue]){
                    int nbrSteps = frontSteps + 1;
                    //u will stop when u have reached the end
                    if(nbrValue == end){
                        return nbrSteps;
                    }
                    q.push({nbrValue, nbrSteps});
                    isVisited[nbrValue] = true;
                }
            }
        }
        //not possible
        return -1;
        
    }
};