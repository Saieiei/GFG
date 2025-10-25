/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
public:

    void inorderTraversal(Node* root, vector<int>& inorderVector){
        //basecase
        if(!root)return;

        //recursion LNR
        inorderTraversal(root->left, inorderVector);
        inorderVector.push_back(root->data);
        inorderTraversal(root->right, inorderVector);
    }

    int findMedian(Node* root) {
        vector<int> inorderVector;
        inorderTraversal(root, inorderVector);

        int ans = 0;
        if(inorderVector.size()%2 == 0) ans = inorderVector[inorderVector.size()/2 -1];
        else ans = inorderVector[inorderVector.size()/2];

        return ans;
    }
};