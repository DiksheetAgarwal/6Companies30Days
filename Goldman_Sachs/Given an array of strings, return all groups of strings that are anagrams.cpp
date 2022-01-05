//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        vector<string> v;
        
        v.push_back(string_list[0]);
        ans.push_back(v);
        v.pop_back();
        
            for(int i=1;i<string_list.size();i++){
                string x = string_list[i];
                sort(x.begin(), x.end());
                
                int f =0;
            for(int j=0;j<ans.size();j++){
              string y = ans[j][0];
              sort(y.begin(), y.end());
                if(x == y){
                        ans[j].push_back(string_list[i]);
                        f=1;
                }
                if(f)
                  break;
            }
            if(!f){
                v.push_back(string_list[i]);
                ans.push_back(v);
                v.pop_back(); 
            }
        
        }
        
        return ans;
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends