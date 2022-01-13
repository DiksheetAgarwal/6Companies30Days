// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        
    vector<vector<int>>dp(K+1, vector<int>(N,0));
    
        for(int t=1;t<=K;t++){
            int m= INT_MIN;
            for(int i=1;i<N;i++){
                m= max(m, dp[t-1][i-1]-A[i-1]);
                dp[t][i]= max(dp[t][i-1], m+A[i]);
            }
        }
        
        return dp[K][N-1];
    
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends