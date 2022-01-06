#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int a[2];
        int *x = a;
        long long sum=0, asum=0;
        long long prod=0, aprod=0;;
        for(int i=0;i<n;i++){
            sum += (long long)(i+1);
            prod += (long long)(i+1)*(long long)(i+1);
            
            asum += (long long)arr[i];
            aprod += (long long)arr[i]*(long long)arr[i];
        }
        
        
        sum = sum-asum;
        prod = prod - aprod;
        
        a[1] = (sum + prod/sum)/2;
        a[0] = a[1]-sum;
        
        
        // a[0] = sum;
        // a[1] = prod;
        
        return x;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends