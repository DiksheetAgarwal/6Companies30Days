

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        if(M== 1 && N ==1 && K ==1)
        return 1;
        int x = M%N;
        K--;
        return ((K+x)%N == 0)? N : (K+x)%N;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}  // } Driver Code Ends