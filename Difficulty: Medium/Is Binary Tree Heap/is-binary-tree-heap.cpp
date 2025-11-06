/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    //1st it should be a CBT
    bool isCompleteTree(Node* root) {
        queue<Node*> q;
        q.push(root);
        bool nullstatus = false;

        while(!q.empty()){
            Node* firstElement = q.front(); q.pop();
            if(firstElement == NULL) nullstatus = true;
            else{
                if(nullstatus) return false;
                q.push(firstElement->left);
                q.push(firstElement->right);
            }
        }
        return true;
    }
    
    //2nd it should follow heap structre
    bool isHeapStructure(Node* root){
        //so in this we have to lST RST and the root
        //basecase
        if(!root)return true;
        if(!root->left && !root->right)return true;
        
        //recursion
        bool LSTAns = isHeapStructure(root->left);
        bool RSTAns = isHeapStructure(root->right);
        
        //root
        bool leftNodeCheck  = (!root->left)  || (root->left->data  < root->data); 
        bool rightNodeCheck = (!root->right) || (root->right->data < root->data);
        bool node = leftNodeCheck && rightNodeCheck;

        //backtracking
        if(LSTAns && RSTAns && node) return true;
        else return false;
    }
    
    //for this we neect to check 2 things
    //1st it should be a CBT
    //2nd it should follow heap structre
    bool isHeap(Node* tree) {
        bool a = isCompleteTree(tree);
        bool b = isHeapStructure(tree);
        return a && b;
        
    }
};