//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Create a memoization array initialized to -1
    int dp[n + 1];
    std::fill(dp, dp + n + 1, -1);

    // Base case
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        // Initialize to a very small number
        dp[i] = INT_MIN;

        // Check each segment length
        if (i >= x) dp[i] = std::max(dp[i], dp[i - x] + 1);
        if (i >= y) dp[i] = std::max(dp[i], dp[i - y] + 1);
        if (i >= z) dp[i] = std::max(dp[i], dp[i - z] + 1);
    }

    // If no solution is found, return 0
    return dp[n] < 0 ? 0 : dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends