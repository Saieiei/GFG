//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        // 1st we will find the potential celebrity
        // for this we will use a stack
        stack<int> st;
        
        // Step 1: push all the people into the stack
        for(int i = 0; i < n; i++)
        {
            st.push(i);
        }
        
        // Step 2: find the potential celebrity
        // Take 2 people out from the stack and check if they know each other
        
        while(st.size() > 1) // Only the potential celebrity should be inside the stack
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            // Now, let's check if a knows b
            if(M[a][b] == 1) 
            {
                // If a knows b, then a is not a celebrity but b can be a celebrity,
                // hence let's push back b into the stack
                st.push(b);
            }
            else 
            {
                // If b knows a, then b is not a celebrity but a can be a celebrity,
                // hence let's push back a into the stack
                st.push(a);
            }
        }
        
        // Step 3: Now, since we have a potential celebrity, we have to check if he doesn't know anyone
        // and if all the people know him
        int candidate = st.top();

        // To check if he doesn't know anyone, we have to see if that row is all 0s
        for(int i = 0; i < n; i++)
        {
            if(M[candidate][i] != 0) return -1;
        }

        // To check if everyone knows him, we have to see if that column is all 1s,
        // except the diagonal, as it's obvious he cannot know himself
        for(int i = 0; i < n; i++)
        {
            if(M[i][candidate] == 0 && i != candidate) return -1;
        }
        
        // Hence we found the potential celebrity
        return candidate;
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
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends