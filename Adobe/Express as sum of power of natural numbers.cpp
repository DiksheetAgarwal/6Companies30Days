// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    // public:
    // int func( vector<int> v, int size, int n,vector<vector<int>>&vi ){
    //     if( n == 0)
    //         return 1;
    //     if( size == 0)
    //         return 0;
        
    //     // if(vi[size][n]!= -1)   return vi[size][n];
    //     if(n-v[size-1]>=0)
    //     return  func(v,size-1, n-v[size-1], vi) + func(v, size-1, n,vi);
        
    //     return func(v,size-1, n, vi);
    // }
    public:
   long long int t[1001][1001];
   long long int mod=1e9+7;
   long long int solve(int n,int x,int i){
       if(n==0){
           return 1;
       }
       if(i>n){
           return 0;
       }
       if(t[n][i]!=-1){
           return t[n][i];
       }
       int pa=pow(i,x);
       if(pa<=n){
           return t[n][i]=(solve(n-pa,x,i+1)+solve(n,x,i+1))%mod;
           
       }
       else{
           return t[n][i]=0;
           
       }
   }
    int numOfWays(int n, int x)
    {
        // code here
        // if( x == 1)
        //     return n/2;
        // vector<int>v ;
        // int till = log(n)/log(x);
        
        // for(int i=1;pow(i,x)<=n;i++)
        //     v.push_back(pow(i,x));

        
        // int size = v.size();
        // vector<vector<int>>vi(size+1, vector<int>(n,-1));
        // int ans =func(v, size, n, vi);
        // return ans;\
        
        
        memset(t,-1,sizeof(t));
       return solve(n,x,1);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends