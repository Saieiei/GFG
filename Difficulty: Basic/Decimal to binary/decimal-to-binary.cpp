//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
    // your code here
    vector<int>digits;
    int temp = N;
    
    while(temp)
    {
        int rem = temp%2;
        temp = temp/2;
        digits.push_back(rem);
    }
    
    reverse(digits.begin(), digits.end());
    for(int i=0; i<digits.size(); i++)
    {
        cout<<digits[i];
    }
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends