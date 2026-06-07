// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int n = arr.size();
        //Binary search LogN
        //since its nearly sorted we have to check 
        //its 1 left and 1 right as well
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            //check if we have reached the target
            if(arr[mid] == target){
                return mid;
            }
            //since its nearly sorted, 
            //check its left and right once
            if(mid + 1 < n && arr[mid + 1] == target){
                return mid + 1;
            }
            else if(mid-1 >=0 && arr[mid-1] == target){
                return mid - 1;
            }
            else{
                //consider the fact that u check 2 elements
                if(target > arr[mid]){
                    low = mid + 2;
                }
                else{
                    high = mid - 2;
                }
            }
        }
        return -1;
    }
};