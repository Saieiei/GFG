//M2 memoization
//Idea: we will 1st finf out the price for length1
//then we will add up with previous ones
//then we will see if it gives us the max value
//we will use a for loop inorder to try all posible lengths
class Solution {
  public:
  
    int recursionMemo(vector<int> &price, int lengthofRod, vector<int>& dp){
        //bc
        if(lengthofRod == 0) return 0;//no price if not rod
        if(dp[lengthofRod] != -1) return dp[lengthofRod];
        int maxProfit = INT_MIN;
        
        
        for(int i = 1; i <= lengthofRod; i++){
            int currPrice = price[i-1];
            int remaingPrice = recursionMemo(price, lengthofRod - i, dp);
            int totalPrice = currPrice + remaingPrice;
            maxProfit = max(maxProfit, totalPrice);
        }
        return dp[lengthofRod] = maxProfit;
    }
  
    int cutRod(vector<int> &price) {
        int lengthofRod = price.size();
        vector<int>dp(lengthofRod + 1, -1);
        return recursionMemo(price, lengthofRod, dp);
        
    }
};