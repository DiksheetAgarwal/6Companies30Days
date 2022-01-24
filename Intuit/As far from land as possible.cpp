class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int vis[n][n];
        memset(vis,0, sizeof(vis));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] =1;       
                }
            }
        }
        if(q.empty() || q.size() == n*n)   return -1;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        int ans =0;
        while(!q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
                pair<int, int> x;
                x = q.front();
                q.pop();
                
                int l = x.first;
                int m = x.second;
                
                
                for(int j=0;j<4;j++){
                    int rx = l+dx[j];
                    int ry = m+dy[j];
                    
                    if(rx<0 || ry<0 || rx>=n || ry>=n || vis[rx][ry])
                        continue;
                    
                    q.push({rx,ry});
                    vis[rx][ry] = 1;
                }                                
            }
            ans++;
        }
        return ans-1;       
    }
};