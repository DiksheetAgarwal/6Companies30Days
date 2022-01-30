//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        // code here
        int maxi =1;
        int m[10001]={0};
        for(int i=0;i<n;i++)
            m[arr[i]]= 1;
        for(int i=0;i<n-1;i++){
            int ma =0;
            for(int j=i+1;j<n;j++){
                int d = arr[j]-arr[i];
                if(d){
                    ma=2;
                    int x = arr[j];
                    while(m[x+d]){
                     ma++;
                     x+=d;
                    }
                    
                    maxi = max(maxi, ma);
                }
            }
        }
        
        return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends