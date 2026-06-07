// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int n = arr.size();
       //brute force
       //linear search O(N)
       for(int i=0; i<n; i++){
           if(arr[i] == target){
               return i;
           }
       }
       return -1;
        
    }
};