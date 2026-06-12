
class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& mat) {
        //this is not sorted https://leetcode.com/problems/row-with-maximum-ones/
        //This 1 is sorted so we should make use of that property
        //matrix cannot be squed
        int m = mat.size();
        int n = mat[0].size();
        //optimial stair case approach 
        //O(M+N)
        int ones = 0;
        int maxRow = -1;
        //traverse through the matrix
        //start from the top right corner then move ur way downwards
        int i = 0, j = n-1;
        while(i<m && j>=0){
            //check if thats a 1
            if(mat[i][j] == 1){
                //if so move left, cuz we found a new record
                j--;
                ones++;
                maxRow = i;
            }
            else{
                //if its a 0, then move down
                i++;
            }
        }
        return maxRow;
    }
};