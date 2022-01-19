#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int a[], int n, long long s)
    {
        vector<int> v;
        long long sum=0;
        int l=0, h=0,f=0;
        while(h<n+1){
            if(sum == s){
                f=1;
                break;
            }
            else if(sum<s){
                sum+=a[h];
                h++;
            }
            else{
                sum-=a[l];
                l++;
            }
        }
        if(f){
        v.push_back(l+1);
        v.push_back(h);
        }
        else v.push_back(-1);
        return v;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends