class Solution {
  public:
    bool isPossible(vector<int> &stalls, int n, int k, int minValue){
        //we require 2 variables
        int currCows = 1;
        int prevPosition = stalls[0];
        //we will traverse through the rest of of the sheds
        //and see see if we can fit them all
        for(int i=1; i<n; i++){
            if(stalls[i] - prevPosition >= minValue){
                //we have found a maximum of the minimum
                //so lets update the 2 variables
                currCows++;
                prevPosition = stalls[i];
                //since we have updated the cows count
                //we have to check if we have plaaced all of them 
                if(currCows == k){
                    return true;
                }
            }
        }
        //we were not able to fit them all in the stalls
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        //binary search
        //maximise the minimum
        //bc
        //if ther emore stalls than the cows
        //we cant fit them
        if(k>n){
            return -1;
        }
        //sort it 1st to apply BS
        sort(stalls.begin(), stalls.end());
        //either the minimum dist btw the cows can be 1
        //or the maximum far apart
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        int ans = -1;
        //start the process of BS
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(stalls, n, k, mid)){
                //we need to maximise the minimum
                //and if its possible for this range means we need to go further
                low = mid + 1;
                ans = mid;
            }
            else{
                //not possible in that range
                //so decrease it
                high = mid - 1;
            }
        }
        return ans;
    }
};