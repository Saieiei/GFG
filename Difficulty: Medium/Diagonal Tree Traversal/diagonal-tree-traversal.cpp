/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        queue<Node*>q;
        vector<int>ans;
        
        if(!root) return ans;
        q.push(root);

        while(!q.empty())
        {
            Node* frontElement = q.front(); q.pop();

            while(frontElement)
            {
                ans.push_back(frontElement->data);

                //we put the left node in the queue, just dont care
                q.push(frontElement->left);

                //then we keep going right
                frontElement = frontElement->right;
            }
        }
        return ans;
        
    }
};