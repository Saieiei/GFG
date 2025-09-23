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
  //we will basically do level order traversal with NULL
  //then simply return the 1st of every vector
    vector<int> leftView(Node *root) {
        vector<vector<int>> LOT;
        vector<int> temp;
        vector<int> ans;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        if(root == NULL) return ans;
        
        while(!q.empty())
        {
            Node* elementNode = q.front();
            q.pop();
            if(elementNode)
            {
                temp.push_back(elementNode->data);
                if(elementNode->left) q.push(elementNode->left);
                if(elementNode->right) q.push(elementNode->right);
            }
            else
            {
                LOT.push_back(move(temp));
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }
        }
        
        for(int i=0; i<LOT.size(); i++)
        {
            ans.push_back(LOT[i][0]);
        }
        return ans;
        
    }
};