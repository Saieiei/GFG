class Solution {
public:
    string findOrder(vector<string>& words) {
        //step1: find the totla no. of nodes
        unordered_map<char, bool> charFound;
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> indegree;

        for(auto word: words) {
            for(auto ch: word) {
                charFound[ch] = true;
            }
        }
        
        int totalNodes = 0;
        for(char ch = 'a'; ch<='z'; ch++) {
            if(charFound[ch] == true) {
                totalNodes++;
            }
        }

        //step2: create grapg by string comparison
        for(int i=0; i+1<words.size(); i++) {
            string word1 = words[i];
            string word2 = words[i+1];

            int minLen = min(word1.size(), word2.size());
            //coapriing string using j index
            int j = 0;

            while(j<minLen && word1[j] == word2[j]) {
                ++j;
            }
            
            //jab main iss loop se bahar aata hu
            // normal case -> you found a non-matching character
            // invalid case -> word2 is a prefix of word1 and word1 > word2
            
            if(j < minLen) {
                //nomal case -> non-matchiong character
                char u = word1[j];
                char v = word2[j];
                adjList[u].push_back(v);
                //u --> v
                indegree[v]++;
            }
            else if(word1.size() > word2.size()) {
                //invalid case
                return "";
            }
        }

        //step3: find topological order
        queue<char> q;
        for(char ch='a'; ch<='z'; ch++) {
            if(charFound[ch] == true && indegree[ch] == 0) {
                q.push(ch);
            }
        }

        string ans = "";
        while(!q.empty()) {
            char frontNode = q.front();
            q.pop();
            //ans store
            ans.push_back(frontNode);
            
            //for this frontNode, decrement the indegree of all nbr
            for(auto nbr: adjList[frontNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        //cout << "My ans: " << ans << endl;
        //step4: check valid or invalid and return ans
        if(ans.length() == totalNodes) {
            return ans;
        }
        else {
            return "";
        }
        
        //word1 -> size > word2 size and word 2 prefix of word 1
        //word2
        //word1 -> abcd
        //word2 -> abc
    }
};