class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        //M1 hashmap
        //since we dont want duplicates, we will use unordered_set
        //push all these vectors to to a unordered_set
        unordered_set<int> seta(a.begin(), a.end());
        unordered_set<int> setb(b.begin(), b.end());
        unordered_set<int> setc(c.begin(), c.end());
        //pick any1 and move on
        vector<int> ans;
        for(const int& it: setc){
            if(seta.count(it) && setb.count(it)){
                //there in all 3
                ans.push_back(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};