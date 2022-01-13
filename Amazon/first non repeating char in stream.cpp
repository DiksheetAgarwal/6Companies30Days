#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		  string ans;
		  int n=a.length();
		  vector<int> vis(26,-1);
		  
		  for(int i=0;i<n;i++){
		      int cnt = n+10, x = a[i]-'a';
		      char ch;
		      //not in map
		      if(vis[x]==-1) vis[x]=i+1;
		      else vis[x]=0;
		      
		      for(int j=0;j<26;j++){
                if(vis[j]>0 && vis[j]<cnt){
                  cnt = vis[j];
                  ch = j+'a';
                }
              }
		      
		      if(cnt == n+10)
		      ans+='#';
		      else ans+= ch;
		  }
		return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends