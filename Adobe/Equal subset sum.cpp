
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool func(int N, int arr[], int sum, vector<vector<int>>&dp){
        if(sum == 0)
            return true;
        if( N ==0)
            return false;
        
        if(dp[N][sum]!=-1)
            return dp[N][sum];
            
        if(arr[N-1]>sum)
            return dp[N][sum] = func(N-1, arr, sum,dp);
        else{
            int taken = func(N-1, arr, sum-arr[N-1],dp);
            int ntaken = func(N-1, arr, sum, dp);
            
            return dp[N][sum] = (taken || ntaken);
        }
    }
    int equalPartition(int n, int arr[]){
        int sum=0;
        for(int i=0;i<n;i++)    sum+=arr[i];
        
        if(sum&1)   return 0;
        else{
            sum/=2;
            vector<vector<int>> dp(n+1,vector<int>(sum+1, -1));
            if(func(n, arr, sum,dp))
                return 1;
            else return 0;
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends