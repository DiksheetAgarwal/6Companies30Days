#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool check( int i, vector<int>&vis , vector<int> &d_v , vector<vector<int>> adj){
        if(vis[i])
            return false;
        vis[i]=1;
        d_v[i]=1;
        for(auto it : adj[i]){
            if(vis[it]==0){
                if(check(it, vis, d_v, adj))
                    return true;
            }
            else if( vis[it] && d_v[it])
                return true;
        }
        d_v[i]=0;
        return false;        
    }
  
    // Function to detect cycle in a directed graph.
    // bool detectCycle(int V, vector<vector<int>> adj){
    //     // code here
        
    //     vector<int> vis(V+1, 0);
    //     vector<int> d_v(V+1, 0);
        
    //     for(int i=0;i< V;i++){
    //         if(vis[i]==0){
    //             if(check(i, vis, d_v, adj))
    //                 return true;
    //         }
    //     }
        
    //     return false;
        
    // }
    
	bool isPossible(int N, vector<pair<int, int> >& prs) {
	    vector<vector<int>> adj(N);
	    for(auto i:prs){
	        adj[i.first].push_back(i.second);
	    }
	    
	    vector<int> vis(N, 0);
        vector<int> d_v(N, 0);
	   
	   for(int i=0;i<N;i++){
	       if(!vis[i]){
	           if(check(i, vis,d_v, adj))
	                return false;
	       }
	   }
	    
	   return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends