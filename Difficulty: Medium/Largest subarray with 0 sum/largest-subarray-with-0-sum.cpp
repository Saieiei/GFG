//it sounds simple but the intuition is not 
//we will use hash map but not in the way u think
//as we go on we will save the csum(key) in hashmap with its index(value)
//so if we find that the csum exists then we have to get its index
    //else just insert it off in hashmap
//now u have the index of the occured csum
    //the ans will be i-index (we will keep storing the max ans only)
//now incase u get csum 0 then its going to be i+1 (we will keep storing the max ans only)
    //i+1 because its caused 100% from the starting only
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int>mp; //csum[key], index[value]

        int csum = 0;
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            csum += arr[i];

            if(csum == 0){
                ans = max(ans, i+1);
            }

            if(mp.find(csum) != mp.end()){
                ans = max(ans, i-mp[csum]);
            }
            else mp[csum] = i;
        }
        return ans;
        
    }
};