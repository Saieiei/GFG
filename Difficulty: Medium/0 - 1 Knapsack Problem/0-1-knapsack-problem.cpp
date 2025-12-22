//M2 Memoization
//we will solve this using include/exclude method
class Solution {
  public:
  
    int recursionMemo(int capacity, vector<int> &val, vector<int> &wt, int index, vector<vector<int>>& dp){
        //3. basecase + check if its there in dp
        if(index >= wt.size()) return 0; //u can keep val.size() also
        if(dp[capacity][index] != -1) return dp[capacity][index];
        
        //recursion
        int include = 0;
        if(wt[index] <= capacity){
            include = val[index] + recursionMemo(capacity-wt[index], val, wt, index+1, dp);
        }
        int exclude = 0 + recursionMemo(capacity, val, wt, index+1, dp);
        
        //2. save it in dp
        dp[capacity][index] =  max(include, exclude);
        return dp[capacity][index];
    }
    
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        //1. create dp
        int index = 0;
        vector<vector<int>>dp (W+1, vector<int>(wt.size()+1, -1));
        return recursionMemo(W, val, wt, index, dp);
        
    }
};