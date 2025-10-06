/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    int toSumTreeHelper(Node* root){
        //basecase
        if(!root)return 0;
        if(!root->left && !root->right){
            int temp = root->data;
            root->data = 0;
            return temp;
        }

        //recursion
        int left = toSumTreeHelper(root->left);
        int right = toSumTreeHelper(root->right);

        int temp = root->data;
        root->data = left + right;

        //backtrack
        return root->data + temp;
    }


//the only catch is that while doing recursion, we also need the value of that node after changing if to sum, for the parent node
    void toSumTree(Node* root) {
        toSumTreeHelper(root);
    }
};