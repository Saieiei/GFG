//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    //week14
    void leafNodeChecker(Node* root, bool& ans, unordered_map<int, bool>& visitedMP)
    {
        if(!root) return;
        //preorder traversal 
        //N
        //we will mark that node as visited
        visitedMP[root->data] = 1;
        if(root->right == NULL && root->left == NULL) //leaf node
        {
            int xp1 = root->data + 1;
            int xm1 = root->data - 1 == 0? root->data : root->data - 1; //this condition is mentioned in the quetion
            if(visitedMP.find(xp1) != visitedMP.end() && visitedMP.find(xm1) != visitedMP.end())
            {
                ans = true;
                return;
            }
        }
        //L
        leafNodeChecker(root->left, ans, visitedMP);
        //R
        leafNodeChecker(root->right, ans, visitedMP);
        
    }
    bool isDeadEnd(Node *root)
    {
        //dead end  is only possible at the leaf nodes
        //o we will do preorder traverasl and find out itf immediate right/ immediate left is present or not
        //to keep the track of the nodes we have to use an unordered MAP
        bool ans = 0;
        unordered_map<int, bool>visitedMP;
        leafNodeChecker(root, ans, visitedMP);
        return ans;
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends