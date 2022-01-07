// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // string repeat( string s, int n){
    //     string x ="";
    //     for(int i=0;i<n;i++)
    //         x+= s;
        
    //     return x;
    // }
    string func( string s, int &i){
        string ans="";
       while(i<s.length() && s[i]!=']'){
            if(!isdigit(s[i])){
                ans+= s[i++];            
            }
            else{
                int no = 0;
                while(i<s.length() && isdigit(s[i]))
                    no = 10*no + s[i++] - '0';
                    
                i++;
                string x = func(s,i);
                i++;
                
                while(no>0){
                    ans += x;
                    no--;
                }
            }
       }
       return ans;
    }

    string decodedString(string s){
        // code here
        int i=0;
        string as = func(s,i);
        
        
        return as;
    }

};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends