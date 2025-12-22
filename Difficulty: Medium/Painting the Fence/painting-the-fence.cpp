//M4 SO
//this is more mathematical => u will get the recursion formula and base case conditions
class Solution {
  public:
  
    int recursionTabuSO(int n, int k){
        //1. create and update dp with BC
        if(n == 1) return k;
        if(n == 2) return k*k;
        
        int curr;
        int prev2 = k;
        int prev1 = k*k;
        
        //recursion formula
        //2. forloop, reverse, copy-paste, rec-fun, indexing
        for(int N=3; N<=n; N++){
            curr =  ((prev1 + prev2) * (k-1));
            
            //exchnage
            prev2 = prev1;
            prev1 = curr;
        }
        
        //3. return accordingly
        return curr;
    }
  
    int countWays(int n, int k) {
        return recursionTabuSO(n, k);
    }
};