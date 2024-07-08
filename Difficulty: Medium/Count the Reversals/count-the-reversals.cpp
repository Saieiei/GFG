//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    //week 11
    //for thi u have to remember the logic that if 2 same bracket sthe count increed by 1
    //else if 2 diff chars then count incresed by 2
    
    //ok lets start now
    stack<int> st;
    
    //1st thing is that if its odd then we cant do anythign 
    if(s.size() & 1 ) return -1;
    
    for(char ch : s)
    {
        if(ch == '{') st.push(ch);
        else //if we get "}"
        {
            if(!st.empty() && st.top() == '{') st.pop();
            else st.push(ch);
        }
    }
    
    int ans=0;
    
    while(!st.empty())
    {
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        
        if(a == b) ans = ans + 1;
        else ans = ans + 2;
    }
    
    return ans;
}