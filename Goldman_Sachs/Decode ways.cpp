#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    
		    long long n = str.length();
		    long long x[n+1];
		    x[0]=1;
		    x[1]= 1;
		    if(str[0] == '0')
		    return 0;
		    for(long long i=2;i<= n;i++){
		        x[i]=0;
		        if(str[i-1] > '0')
		            x[i]+=(x[i-1])%1000000007;
		            
		           if(str[i-2] =='1' || (str[i-2]=='2' && str[i-1]<'7'))
		            x[i]+=(x[i-2])%1000000007;
		    }
		    return x[n]%1000000007;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends