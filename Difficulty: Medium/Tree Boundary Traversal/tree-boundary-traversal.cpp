/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void leftTraversal(Node* root, vector<int>& ans)
    {
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL)return;
        
        ans.push_back(root->data);
        
        if(root->left != NULL) leftTraversal(root->left, ans);
        else leftTraversal(root->right, ans);
    }
    
    void leafTraversal(Node* root, vector<int>& ans)
    {
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
    }
    
    void rightTraversal(Node* root, vector<int>& ans)
    {
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL)return;
        
        if(root->right != NULL) rightTraversal(root->right, ans);
        else rightTraversal(root->left, ans);
        
        ans.push_back(root->data);
    }

    //to solve this we will traverse left sub tree, then leaf nodes[leaft(left), leaf(right)] and then right sub tree
    //in the leftSubTree make sure its a left node then prefere left then right nodes
    //in the leafSubTree make sure they r leaf nodes, simply return, then make recursive calls
    //in the rightSubTree make sure that they r right nodes and prefer right then left and moreover we need it in reverse
        //so we have to 1st do recursion and then push in nodes val
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        
        if(root == NULL)return ans;
        else ans.push_back(root->data);
        
        leftTraversal(root->left, ans);
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
        rightTraversal(root->right, ans);
        
        return ans;
    }
};