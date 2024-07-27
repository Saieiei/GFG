//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

            // Create the right child for the current node
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
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
public:
    // Function to calculate the height and sum of nodes on the longest path
    pair<int, int> height(Node* root) {
        // Base case: If the node is null, height and sum are 0
        if (!root) return {0, 0};
        
        // Recursively calculate the height and sum for the left and right subtrees
        auto leftResult = height(root->left);
        auto rightResult = height(root->right);
        
        // Calculate the current sum including the root node's data
        int sum = root->data;
        
        // If the left and right subtrees have the same height,
        // choose the path with the greater sum
        if (leftResult.first == rightResult.first) {
            sum += max(leftResult.second, rightResult.second);
        }
        // If the left subtree is taller, include its sum
        else if (leftResult.first > rightResult.first) {
            sum += leftResult.second;
        }
        // If the right subtree is taller, include its sum
        else {
            sum += rightResult.second;
        }
        
        // Return a pair consisting of the height of the current node and the calculated sum
        return {max(leftResult.first, rightResult.first) + 1, sum};
    }
    
    // Function to find the sum of nodes on the longest path from root to leaf
    int sumOfLongRootToLeafPath(Node* root) {
        // Call the height function to get the sum of the longest path
        auto result = height(root);
        return result.second; // Return the sum component of the pair
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends