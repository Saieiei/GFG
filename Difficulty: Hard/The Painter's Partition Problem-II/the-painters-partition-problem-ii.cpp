class Solution {
  public:
    bool isPossible(vector<int>& arr, long long  n, long long k, long long maxValue){
        //we require 2 variables
        long long currWorkers = 1;
        long long sumTime = 0;
        //traverse through the arr and check if we r able to fit all the workers
        //in the given range
        for(int i=0; i<n; i++){
            if(arr[i] > maxValue){
                //if the minimum is already maximum then we cant do anything
                return false;
            }
            if(arr[i] + sumTime > maxValue){
                //when the minimum exceeds the maxValue only by adding the sumTime
                //then we need to update the number of workers and the sumTime
                currWorkers++;
                sumTime = arr[i];
                //since we have updated the numWorkers, we have to see it doesnt exceeds
                if(currWorkers > k){
                    return false;
                }
            }
            else{
                //at thsi point it is not bale to maximum
                //so we should increase the sumTime
                sumTime += arr[i];
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        long long n = arr.size();
        //this is same as allocate minimum pages
        //binary search on the naswer
        //minimise the maximum
        //bc
        //more number of painters boards, then not possible
        //not needed cuz the workers can be ideal if necessary
        //if(n>k){
        //    return false;
        //}
        //it can either be the maximum length of the boards
        //or 1 person has to do everything
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = -1;
        //start the process BS
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(isPossible(arr, n, k, mid)){
                //if its possible then this range is possible
                //but we have to minimise the maximum
                //we we have to decrase the range
                high = mid-1;
                ans = mid;
            }
            else{
                //that range was not possible cuz it was too small
                //we need to increase the range
                low = mid + 1;
            }
        }
        return ans;
    }
};