//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int f=0;
        int ans=0;
        if(str[0]=='-')
            f=1;
        else if(!(str[0]>='0' && str[0]<='9'))
            return -1;
        else ans = str[0]-'0';
        for(int i=1;i<str.length();i++){
            if(!(str[i]>='0' && str[i]<='9'))
                return -1;
            int rem = str[i]-'0';
            ans = 10*ans+rem;
        }
        
        return (f==1)? -ans:ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends