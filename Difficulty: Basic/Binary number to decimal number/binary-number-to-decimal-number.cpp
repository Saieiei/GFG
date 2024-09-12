//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string str) {
        // Code here.
        int counter = 0;
        int ans = 0;
        reverse(str.begin(), str.end());
        for(char ch: str)
        {
            int digit = ch - '0';
            ans = ans + digit*(pow(2, counter));
            counter++;
        }
        return ans;
    }
        
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends