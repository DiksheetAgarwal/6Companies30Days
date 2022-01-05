#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull v[n];
        ull x=0,y=0,z=0;
        v[0]= 1;
        
	    for(ull i=1;i<n;i++)
	    {
	       v[i] = min(v[x]*2, min(v[y]*3, v[z]*5));
	       
	       if(v[i] == v[x]*2)   x++;
	       if(v[i] == v[y]*3)   y++;
	       if(v[i] == v[z]*5)   z++;
	                
	    }
	    return v[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends