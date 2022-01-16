#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>>ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1, h= n-1;
                
                while(l<h){
                    int sum = arr[i]+arr[j]+arr[l]+arr[h];
                    if(sum<k)
                        l++;
                    else if(sum>k)
                        h--;
                    else{
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[l]);
                        v.push_back(arr[h]);
                        
                        int x = arr[l];
                        while(l<n && arr[l]==x)
                        l++;
                        
                        x= arr[h];
                        while(h>=0 && arr[h]==x)
                        h--;
                        ans.push_back(v);
                    }
                }
                while(j+1<n && arr[j+1]==arr[j])
                    j++;
            }
                while(i+1<n && arr[i+1]==arr[i])
                    i++;
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends