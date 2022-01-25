class Solution {
public:
    void dfs(vector<int> adj[], int i, vector<int>&vis){
        
        if(vis[i])  return;        
        vis[i] = 1;
        for(auto x: adj[i]){
            dfs(adj, x, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);   
                }
            }
        }
        
        
        vector<int>vis(n,0);
        int cnt =0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                cnt++;
            }                
        }
        
        return cnt;     
    }
};