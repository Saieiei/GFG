/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
  
  
    void checker(Node *root, unordered_map<int, bool>& visitedStatus, bool& ans){
        //basecase
        if(!root)return;
        
        visitedStatus[root->data] = true;
        if(root->left == NULL && root->right == NULL){
            int rightNodeVal = root->data + 1;
            //special case for 1
            int leftNodeVal = root->data - 1 <=0 ? 1 : root->data -1;
            
            if(visitedStatus.find(rightNodeVal) != visitedStatus.end() 
                && visitedStatus.find(leftNodeVal) != visitedStatus.end()){
                    ans = true;
                    return;
            } 
        }
        //recursion
        checker(root->right, visitedStatus, ans);
        checker(root->left, visitedStatus, ans);
        
    }
    
    //the idea being we have to check 1st if its a leaf node 1st
    //then we will find its left and right node
    //we will check if these nodes were already visited (unordered_map<int, bool>)
    //if already visisted, both of them , then return true
    //else return false
    bool isDeadEnd(Node *root) {
        bool ans = false;
        unordered_map<int, bool> visitedStatus;
        
        checker(root, visitedStatus, ans);
        return ans;
        
    }
};