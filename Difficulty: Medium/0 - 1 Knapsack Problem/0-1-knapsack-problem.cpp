//M4 TabulationSO2
//we will solve this using include/exclude method
class Solution {
  public:
  
    int recursionTabuSO2(int capacity, vector<int> &val, vector<int> &wt, int index){
        //solve it using 2 cols
        int n = wt.size();
        //vector<int> curr(capacity+1, 0);
        vector<int> next(capacity+1, 0);
        
        //we have revered row and col because we r filling it col wise
        for(int i = n-1; i>=0; i--){
            for(int c = capacity; c>=0; c--){ //reverse this
                int include = 0;
                if(wt[i] <= c){
                    include = val[i] + next[c-wt[i]]; //dp[i+1] = next
                }
                int exclude = 0 + next[c];
        
                //2. save it in dp
                next[c] =  max(include, exclude); //dp[i] = curr
            }
            //shifting
            //next = curr;
        }
        return next[capacity];
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        //1. create dp
        int index = 0;
        return recursionTabuSO2(W, val, wt, index);
        
    }
};