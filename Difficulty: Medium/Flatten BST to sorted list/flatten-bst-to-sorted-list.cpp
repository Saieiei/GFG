/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:


    void inorderTraversal(Node* node, Node*& head, Node*& prev){
        //basecase
        if(!node)return;

        //recursion LNR
        inorderTraversal(node->left, head, prev);

        if(!prev) head = node; //only once
        else prev->right = node;

        node->left = NULL;
        prev = node;

        inorderTraversal(node->right, head, prev);
    }

    //the intuition is basically to use inorder traversal
    //so we will use head and prec pointers
    //so the head pointer will 1st go to the extereme left and get initialised (only once in the entier process)
    //now we need to break the tree, so the node left is null and prev comes on the node
    //during th enext iteration the prev right will be pointing to the node (since we have prev now)
    //and so on 
    Node* flattenBST(Node* root) {
        Node* head = NULL;
        Node* prev = NULL;
        inorderTraversal(root, head, prev);

       return head;
    }
};