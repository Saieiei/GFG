//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
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
  //this 1 is a little hard only
    int burnTheTree(Node* targetNode, unordered_map<Node*, Node*>& parentMap)
    {
        //only when the fire is spread we will increase the time
        //we will push the nodes in te queue which r being burnt
        //we should also make a map such that we can check if that node is already burnt or not
        unordered_map<Node*, bool>isBurnt;
        int t = 0;
        queue<Node*> q;
        q.push(targetNode);
        isBurnt[targetNode] = 1;
        
        while(!q.empty())
        {
            int size = q.size();
            bool isFireSpread = 0;
            for(int i = 0; i<size; i++)
            {
                Node* front = q.front(); q.pop();
                //we will go to childrens
                if(front->left && !isBurnt[front->left])
                {
                    q.push(front->left);
                    isBurnt[front->left] = 1;
                    isFireSpread = 1;
                }
                if(front->right && !isBurnt[front->right])
                {
                    q.push(front->right);
                    isBurnt[front->right] = 1;
                    isFireSpread = 1;
                }
                //now we will go to parents
                if(parentMap[front] && !isBurnt[parentMap[front]])
                {
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]] = 1;
                    isFireSpread = 1;
                }
            }
            if(isFireSpread) t++;
        }
        return t;
    }
    Node* makeNodeToParnetNodeAndFindTargetNode(Node* root, int target, unordered_map<Node*, Node*>& parentMap)
    {
        //we will use inorder traversal, it doesnt matter which order u choose
        queue<Node*>q;
        Node* targetNode = 0;
        q.push(root);
        parentMap[root] = 0;
        
        while(!q.empty())
        {
            Node* front = q.front(); q.pop();
            if(front->data == target) targetNode = front;
            if(front->left)
            {
                q.push(front->left); parentMap[front->left] = front;
            }
            if(front->right)
            {
                q.push(front->right); parentMap[front->right] = front;
            }
        }
        return targetNode;
    }
    int minTime(Node* root, int target) 
    {
        //for this code to take place, we nned to have the parent nodes of every node
        //we also need to find the targetNode in Node* as it is given to us in int
        
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = makeNodeToParnetNodeAndFindTargetNode(root, target, parentMap);
        int ans = burnTheTree(targetNode, parentMap);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends