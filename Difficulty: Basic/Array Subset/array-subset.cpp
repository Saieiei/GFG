#include <unordered_map>
//this is just too easy with hashmaps
//first put all the elements of arr1 in hahsmaps
//then while iterating through arr2, even if 1 element is not found then return false
//in the end return true
class Solution {
public:
    bool isSubset(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;
        
        for(int element_arr1: arr1){
            freq[element_arr1]++;
        }

        for(int element_arr2: arr2){
            if(freq.find(element_arr2) == freq.end() || 
                (freq.find(element_arr2) != freq.end() && freq[element_arr2] <= 0))
                    return false;
            else freq[element_arr2]--;
        }
        
        return true;
    }
};