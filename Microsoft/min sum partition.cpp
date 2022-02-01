#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	  //dp subset sum problem;
	  
	  int sum =0;
	  for(int i=0;i<n;i++)  sum+=arr[i];
	  
	  int dp[n+1][sum+1];
	  
	  for(int i=0;i<n+1;i++){
	      for(int j=0;j<sum+1;j++){
	          if(j == 0)   dp[i][j] = 1;
	          else if( i==0)    dp[i][j] = 0;
	          else{
	              if(j- arr[i-1]>=0)    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	              else  dp[i][j] = dp[i-1][j];
	          }
	      }
	  }
	  int ans =INT_MAX;
	  for(int i=0;i<=sum/2;i++){
	      if(dp[n][i] == 1)
	        ans = min(ans, sum-(2*i));
	  }
	  return ans;
	  
	  
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends