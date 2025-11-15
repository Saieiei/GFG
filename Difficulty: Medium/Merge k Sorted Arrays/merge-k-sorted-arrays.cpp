class info{
 public:
    int row;
    int col;
    int value;
    info(int valData, int rowData, int colData): value(valData), row(rowData), col(colData) {}
};

class compare{
 public:
    bool operator()(info* a, info* b){
        return a->value > b->value;
    }
};

//we will use min heap for this
//we will be using our custome datasture, which will have the vector value, its row and col
//then since its min heap, we have to make our custome greater<int>
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int matRow = mat.size();
        int matCol = mat[0].size();
        
        //now this trick is similar to leverl order traversal
        //1st we put in the elements
        //then untill the while loop is over, we keep adding elements in order
        
        vector<int> ans;
        priority_queue<info*, vector<info*>, compare>pq;
        
        //1st we put in the elements i.e 1st element of each row
        for(int i=0; i<matRow; i++){
            info* temp = new info(mat[i][0], i, 0);
            pq.push(temp);
        }
        
        //then until the while loop is over, we keep adding elements in order
        while(!pq.empty()){
            info* front =pq.top(); pq.pop();
            ans.push_back(front->value); 
            
            int currCol = front->col;
            int currRow = front->row;
            if(currCol + 1 < mat[currRow].size()){
                info* temp = new info(mat[currRow][currCol + 1], currRow, currCol + 1);
                pq.push(temp);
            }

        }
        return ans;
        
    }
};