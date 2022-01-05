#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here 
  int n = s.length();
  string ans ="";
  
  int i=0;
  while(i<n){
      int count=1;
      if(i<n-1 && s[i] == s[i+1]){
          while(i<n-1 && s[i] == s[i+1]){
              count++;
              i++;
          }
          ans += s[i];
          string x = to_string(count);
          ans += x;
          i++;
      }
      else{
          ans += s[i];
          ans += (count + '0');
          i++;
      }
  }
  
  return ans;
}     
 
