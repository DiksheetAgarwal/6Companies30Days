//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void func(int n, vector<string>&v, int open, int close, string x){
        if(open == n && close == n){
            v.push_back(x);
            return;
        }
        
        if(open<n){
            func(n,v,open+1, close, x+'(');
        }
        if(open>close){
            func(n,v,open, close+1, x+')');
        }
       
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> v;;
        func(n, v, 0,0,"");
        return v;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends