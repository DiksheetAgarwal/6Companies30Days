//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    void func( int i, int j,int a, int b, int &ans){
        if(i>a || j>b)  return;
        if(i == a-1 && j == b-1){
            ans++;
            return ;
        }    
        
        func(i,j+1, a,b,ans);
        func(i+1,j, a,b,ans);
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        int ans =0;
        func(0,0,a, b, ans);
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends