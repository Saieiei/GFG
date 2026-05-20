class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        int n = arr.size();
        //can only be done via hashing
        //because [1, n] not guaranteed
        //and require 1st duplicate, X sorting
        
        unordered_map<int, int>mp;
        //populate the freq
        for(int num: arr){
            mp[num]++;
        }
        
        //traverse through the arr and check if the freq is more than 1
        for(int i=0; i<n; i++){
            int num = arr[i];
            if(mp[num] > 1){
                return i+1;
            }
        }
        //couldnt find any duplicates
        return -1;
    }
};