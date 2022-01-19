#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans = "";
        if(s[0]<=90) ans+= s[0]+32;
        else ans+=s[0];
        
        for(int i=1;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90){
                ans+=' ';
                ans+= s[i]+32;
            }
            else ans+=s[i];
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends