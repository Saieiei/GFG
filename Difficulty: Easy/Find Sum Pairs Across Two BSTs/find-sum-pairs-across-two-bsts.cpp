/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:

    void inorderTraversal(Node* root, vector<int>& inorderVectorRoot){
        //basecase
        if(!root)return;
        //recursion LNR
        inorderTraversal(root->left, inorderVectorRoot);
        inorderVectorRoot.push_back(root->data);
        inorderTraversal(root->right, inorderVectorRoot);
    }

    int countPairs(Node* root1, Node* root2, int x) {
        vector<int> inorderVectorRoot1;
        vector<int> inorderVectorRoot2;
        inorderTraversal(root1, inorderVectorRoot1);
        inorderTraversal(root2, inorderVectorRoot2);
        
        unordered_set<int> inorderSetRoot2(inorderVectorRoot2.begin(), inorderVectorRoot2.end());

        int ans =0;
        for(int value: inorderVectorRoot1){
            int need = x-value;
            if(inorderSetRoot2.count(need)) ans++;
        }
        return ans;
    }
};