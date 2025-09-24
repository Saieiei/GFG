/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
  
    void leftViewHelper(Node* root, int level, vector<int>& ans)
    {
        //base case
        if(root == NULL) return;
        if(level == ans.size()) ans.push_back(root->data); level++;
        
        //recursion
        leftViewHelper(root->left, level, ans);
        leftViewHelper(root->right, level, ans);
    }
  
  //to solve this we will use method 2 that is verifying the levelsr
    vector<int> leftView(Node *root) {
        vector<int> ans;
        int level = 0;
        leftViewHelper(root, level, ans);
        return ans;
    }
};