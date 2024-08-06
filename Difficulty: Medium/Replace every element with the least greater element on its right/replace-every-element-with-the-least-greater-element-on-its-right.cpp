//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(NULL), right(NULL) {};
};

class Solution{
    public:
    Node* BSTMaker(Node* root, int& succ, int val)
    {
        if(!root) return new Node(val); //st create a node with the value
        
        if(val>= root->data) root->right = BSTMaker(root->right, succ, val);
        else
        {
            succ = root->data;
            root->left = BSTMaker(root->left, succ, val);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        //the best way to solve this q is through BST
        //when ever we go left we will update the ans vector
        int succ = -1;
        Node* root = NULL;
        vector<int> ans(arr.size(), -1);
        
        for(int i=arr.size()-1; i>=0; i--)
        {
            succ = -1;
            root = BSTMaker(root, succ, arr[i]); //the value of succ will be chnaged in here
            ans[i] = succ;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends