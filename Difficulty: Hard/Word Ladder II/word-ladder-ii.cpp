
//BFS with currSequence
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        //bc
        if (beginWord == endWord) return ans;
            //If the target word isn't even in the dictionary, we can save a lot of time by exiting immediately.
        if (st.find(endWord) == st.end()) return ans;
        
        queue<pair<vector<string>, int>> q;
        vector<string> currSeq;
        currSeq.push_back(beginWord);
        q.push({currSeq, 1}); //word, iteration
        vector<string> toDelete;
        int prevIteration = 0;

        while(!q.empty()){
            pair<vector<string>, int> frontNode = q.front();
            q.pop();
            vector<string> currSeq = frontNode.first;
            string currWord = currSeq[currSeq.size()-1];
            int iteration = frontNode.second;

            //delete if the iteration has chnaged
            if(iteration > prevIteration){
                for(string word: toDelete){
                    st.erase(word);
                }
                toDelete.clear();
                prevIteration = iteration; //increase the prevIteration
            }

            //check
            if(currWord == endWord){
                ans.push_back(currSeq);
                continue; //no need to find the next next words
            }

            //create new word
            for(int index = 0; index<currWord.length(); index++){
                string originalWordSave = currWord;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    currWord[index] = ch; //curWord has been changed
                    string newWord = currWord;
                    if(st.find(newWord) != st.end()){ //found the word
                        vector<string> temp(currSeq.begin(), currSeq.end());
                        temp.push_back(newWord);
                        q.push({temp, iteration + 1});
                        toDelete.push_back(newWord); //isVisted
                    }
                }
                currWord = originalWordSave;
            }
        }
        return ans;
    }
};