//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    void recurssionInsertAtTheBottom(stack<int> &st, int& x)
    {
        //base case
        if(st.empty())
        {
            st.push(x);
            return;
        }
        
        //we will solve 1 case now, recurssion
        int temp = st.top();
        st.pop();
        recurssionInsertAtTheBottom(st, x);
        
        //backtracking
        st.push(temp);
        
        
    }

    void recurssion1TraverseTillLast(stack<int> &st)
    {
        //base case
        if(st.empty()) //do nothign
        {
            return;
        }
        
        //we will solve 1 case now, recurssion 
        int temp = st.top();
        st.pop();
        recurssion1TraverseTillLast(st);
        
        //backtracking
        recurssionInsertAtTheBottom(st, temp);
    }
    void Reverse(stack<int> &st){
        //we will solve this using recurssion
        //but to understand this, we have to 1st solve th eq, insert at the bottom of the stack problem, whoch is again then using recurssion
        
        recurssion1TraverseTillLast(st);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends