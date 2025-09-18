class Solution {
  public:
    string FirstNonRepeating(string &s) {
        //to solve this we will use deque and hasmap
        //haspmap will be used to store the count of the steam
        //deque will store the index of the char of s
        //we will take each element and push it into the queue and update the hashmap count
        //while the front->count = 1 then that will be the ans and we proceed for the next char
        //else we will keep poping until we get 1 or empty
            //if empty then push in hash into the ans
            //else obio the front which will have count = 1
        //finally return the ans
        
        string ans;
        deque<int> dq;
        unordered_map<char, int>freq;
        
        for(int i=0; i<s.length(); i++)
        {
            char element = s[i];
            freq[element]++;
            //simply push it in dq
            dq.push_back(i);
            while(!dq.empty())
            {
                if(freq[s[dq.front()]]==1)
                {
                    ans.push_back(s[dq.front()]);
                    break;
                }
                else
                {
                    dq.pop_front();
                }
                
            }
            if(dq.empty()) ans.push_back('#');
        }
        return ans;
        
    }
};