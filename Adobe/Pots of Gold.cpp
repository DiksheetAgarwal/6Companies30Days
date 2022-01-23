//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int func( vector<int>&A, int start, int end, vector<vector<int>> &v){
    if(start > end) return 0;
    if(v[start][end]!= -1)   return v[start][end];
    int left = A[start] + min(func(A, start+2, end,v), func(A, start+1, end-1,v));
    int right = A[end] + min(func(A,start, end-2,v), func(A, start+1, end-1,v));
    
    return v[start][end] = max( left, right);
}
    int maxCoins(vector<int>&A,int n)
    {
        vector<vector<int>>v(n,vector<int>(n,-1));
	    int ans = func(A,0,n-1,v);
	    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends