#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
string func(int i){
    string x;
    while(i>0){
        int rem = i%2;
        x += rem+'0';
        i/=2;
    }
    reverse(x.begin(), x.end());
    return x;
}
vector<string> generate(int N)
{
    vector<string> ans;
	for(int i=1;i<=N;i++)
	    ans.push_back(func(i));
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends