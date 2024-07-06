//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // Function to delete the middle element of a stack.
    void recursion(stack<int>& s, int current, int middle) {
        // Base case: If current position is middle, pop the element and return.
        if (current == middle) {
            s.pop();
            return;
        }
        
        // Remove the top element and call recursion to reach middle.
        int temp = s.top();
        s.pop();
        recursion(s, current + 1, middle);
        
        // Push the top element back onto the stack.
        s.push(temp);
    }

    void deleteMid(stack<int>& s, int sizeOfStack) {
        // Calculate the middle index.
        int middle = sizeOfStack / 2;
        
        // Start recursion from the 0th position.
        recursion(s, 0, middle);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends