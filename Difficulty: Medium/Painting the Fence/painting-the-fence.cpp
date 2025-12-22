//M2 Memoization
//this is more mathematical => u will get the recursion formula and base case conditions
class Solution {
  public:
  
    int recursionMemo(int n, int k, vector<int>& dp){
        //basecase
        //3. check if its there in dp
        if(n==1) return k;
        if(n==2) return k*k;
        if(dp[n] != -1)  return dp[n];
        
        //recursion formula
        //2. save the res in dp
        
        dp[n] =  ((recursionMemo(n-1, k, dp) + recursionMemo(n-2, k, dp)) * (k-1));
        return dp[n];
    }
  
    int countWays(int n, int k) {
        //1. create dp
        vector<int>dp(n+1, -1);
        return recursionMemo(n, k, dp);
        
    }
};