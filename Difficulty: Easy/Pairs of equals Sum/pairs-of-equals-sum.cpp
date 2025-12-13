
//the logic is same as the two sums
//we will use hashmaps here
class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        //the idea is that we will make all posible pairs witout overlapping
        //initially all the sum of these pairs is marked false
        //as soon as u get a pair u mark it true, then when u find it in the map gain return true
        unordered_map<int, bool>sum_marker_mp;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                int sum = arr[i] + arr[j];
                
                //1st check if that sum is present in the mp
                if(sum_marker_mp.find(sum) != sum_marker_mp.end()){
                    return true;
                }
                else sum_marker_mp[sum] = true;
            }
        }
        return false;
    }
};