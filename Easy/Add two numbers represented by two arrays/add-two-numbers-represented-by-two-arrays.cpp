//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        int i=n-1;
        int j=m-1;
        string ans;
        int carry=0;
        
        
        // 1234
        // 1234    
        while(i>=0 && j>=0)
        {
            int sum=a[i]+b[j]+carry;
            int digit=sum%10;
            carry=sum/10;
            ans.push_back(digit+'0');
            i--,j--;
            
        }
        
        // 1234
        //  123
        while(i>=0)
        {
            int sum=a[i]+0+carry;
            int digit=sum%10;
            carry=sum/10;
            ans.push_back(digit+'0');
            i--;
            
        }
        
        //  123
        // 1234
        while(j>=0)
        {
            int sum=0+b[j]+carry;
            int digit=sum%10;
            carry=sum/10;
            ans.push_back(digit+'0');
            j--;
            
        }
        
        //incase carry in the left most digit
        //123
        //911
        if(carry)
        {
            ans.push_back(carry+'0');
        }
        
        
        //0 0 0 0 9 0 0 3 5
        //            2 2 7
        //0 0 0 0 9 0 2 6 2 ==> 90262
        while(ans[ans.size()-1]=='0')
        {
            ans.pop_back();
        }
        
        //1234
        //1234
        //2468 but ans=8642
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends