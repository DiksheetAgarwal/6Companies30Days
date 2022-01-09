
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        
        vector<string> contacts;
        for(int i=0;i<n;i++){
            contacts.push_back(contact[i]);
        }
        vector<vector<string>> ans;
        string comp="";
        sort(contacts.begin(), contacts.end());
        for(int i=0;i<s.length();i++){
            vector<string> v;
            comp+=s[i];
            int x = comp.length();
            for(int j=0;j<n;j++){
                string temp = contacts[j].substr(0, x);
                if(temp == comp && std::find(v.begin(), v.end(),contacts[j])== v.end())
                    v.push_back(contacts[j]);
            }
            if(v.size()==0)
                v.push_back("0");
            ans.push_back(v);
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends