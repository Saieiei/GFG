//u have to know the word ladder I
//BFS
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        //keep the copy of wordList in set so that we can erase it, works as isVisited[]
        unordered_set<string> dupWordList(wordList.begin(), wordList.end());

        //in the queue we will be pushing back the entier path
        //we will only remove the word from the wordlist, once we r done with the words on that level
        queue<vector<string>> q;
        q.push({beginWord});

        //trackers
        vector<string> wordsOnThatLevel;
        wordsOnThatLevel.push_back(beginWord);

        //initial level is 0
        int level = 0;
        vector<vector<string>> ans;

        //start the process BFS
        while(!q.empty()){
            vector<string> frontEntierPath = q.front();
            q.pop();
            //check if the level has been increased
            //if so we need to to reset the wordsOnThatLevel and erase words from the set, cuz all r done
            //dont have to visit them again
            int FrontEntierPathSize = frontEntierPath.size();
            if(FrontEntierPathSize > level){
                //update the level
                level++;
                //delete these words if present in the dupWordList and 
                //clear the wordsOnThatLevel for the next batch
                for(const string& word: wordsOnThatLevel){
                    dupWordList.erase(word);
                }
                wordsOnThatLevel.clear();
            }

            //if we r new level, that means new word must have been added
            //check if the last word added is the endWord
            string lastWordFrontEntierPath = frontEntierPath.back();
            if(lastWordFrontEntierPath == endWord){
                //we have reached the end of this entier path
                //now we have to push it in the ans
                //if nothing is there in the ans, then this is the very 1st entry
                //very 1st entry in BFS is the shortest, so we can blindly push
                //else we have to compare the size of the previous and push only if same size
                //or ans.empty()
                if(ans.size() == 0){
                    ans.push_back(frontEntierPath);
                }
                else{
                    if(FrontEntierPathSize == ans[0].size()){
                        ans.push_back(frontEntierPath);
                    }
                }
                //very imp
                continue; // Skip generating neighbors for the endWord
            }

            //now lets create the new words, like in word Ladder I
            int indexSize = lastWordFrontEntierPath.size();
            for(int index = 0; index<indexSize; index++){
                //create the new word
                for(char ch = 'a'; ch<='z'; ch++){
                    string newWord = lastWordFrontEntierPath;
                    newWord[index] = ch;
                    //check if this is present in the dupWordList
                    //u can use dupWordList.count(newWord) as well
                    auto it = dupWordList.find(newWord);
                    if(it != dupWordList.end()){
                        //found it
                        //if so, insert it in the current path and in the wordsOnThatLevel
                        wordsOnThatLevel.push_back(newWord);
                        frontEntierPath.push_back(newWord);
                        //now push the new path in the queue for processing
                        q.push(frontEntierPath);
                        //now remove that last inserted new word for the pther path on the same level to be formed
                        frontEntierPath.pop_back();
                    }
                }
            }
        }
        //finally return the ans
        return ans;
    }
};