//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/* 146 /159
Time Limit Exceeded
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       //vector<int>stprice(n);
       //for(int i=0; i<n; i++)
      // {
       //    stprice[i] = price[i];
       //}
       vector<int> ans(n);
       for(int i=0; i<n; i++)
       {
           int counter = 0;
           for(int j=i; j>=0; j--)
           {
               if(price[i] >= price[j]) counter++;
               else break;
           }
           ans[i] = counter;
       }
       return ans;
    }
};
*/
class Solution
{
public:
    // Function to calculate the span of stock’s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Vector to store the result of spans.
        vector<int> span(n);
        
        // Stack to store indices of the days.
        stack<int> s;
        
        // Process each day's price.
        for (int i = 0; i < n; i++)
        {
            // While stack is not empty and the price at the top of the stack
            // is less than or equal to the current price, pop the stack.
            while (!s.empty() && price[s.top()] <= price[i])
            {
                s.pop();
            }
            
            // If the stack becomes empty, it means the current price is greater
            // than all the previous prices, so the span is i+1 (from the first day).
            // Otherwise, the span is the difference between the current index and 
            // the top of the stack (which is the nearest greater price day).
            if (s.empty())
            {
                span[i] = i + 1;
            }
            else
            {
                span[i] = i - s.top();
            }
            
            // Push the current day's index onto the stack.
            s.push(i);
        }
        
        return span;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends