//this is a graph q
//we will solve it via topological sorting
//we have to convert the given data into graph
//each node is a letter
class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        //step1 find out how many unique letters r there
        //because we need that in our ans
        //and if the size of the ans dont match out
        //then not possible
        //during this process we will create the base of topo
        //that is to create indegrees
        unordered_map<char, int> indegrees;
        int totalNodes = 0;
        unordered_map<char, bool> isVisited;
        for(string word: words){
            for(char ch: word){
                if(isVisited[ch] == false){
                    totalNodes++;
                    isVisited[ch] = true;
                    indegrees[ch] = 0;
                }
            }
            
        }
        
        //2nd step is to create the graph
        unordered_map<char, vector<char>> adjList;
        //now while creating the adjList,
        //we will have idea regarding indegrees of each node
        //we will take 2 word from the given words
        //now we can face issues with abnormal values
        //if word2 is a subset of word1, then we cant do it
        string ans = "";
        for(int i=0; i+1<n; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int word1Size = word1.size();
            int word2Size = word2.size();
            int minWordLength = min(word1Size, word2Size);
            
            //find the index where the chars r not the same
            int j=0;
            while(word1[j] == word2[j] && j<minWordLength){
                j++;
            }
            //we have the index now
            //but we have to check if its safe
            if(j<minWordLength){
                //safe
                //u->v
                //directed
                char u = word1[j];
                char v = word2[j];
                adjList[u].push_back(v);
                indegrees[v]++;
            }
            else if(word1Size > word2Size){
                //not safe, not possible to proceed
                return "";
            }
        }
        
        //now start the normal topo process
        queue<char> q;
        for(pair<const char, int> data: indegrees){
            char node = data.first;
            int indegree = data.second;
            if(indegree == 0){
                q.push(node);
            }
        }
        while(!q.empty()){
            char frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            //preocess its nbrs
            for(char nbr: adjList[frontNode]){
                indegrees[nbr]--;
                if(indegrees[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        //now u have the ans ready
        //check if it has all the unique letters
        if(ans.size() != totalNodes){
            //not possible
            return "";
        }
        return ans;
        
    }
};