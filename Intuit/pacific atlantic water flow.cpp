class Solution {
public:
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    void dfs( vector<vector<int>>heights, vector<vector<int>>&vis, int i, int j){
        int n = heights.size();
        int m = heights[0].size();
        
        vis[i][j] = 1;
        
        for(int k =0;k<4;k++){
            int rx = i+dx[k], ry = j+dy[k];
            if(rx<0 || ry<0 || rx>=n || ry>=m)    continue;
            if(vis[rx][ry] || heights[i][j]>heights[rx][ry])    continue;
            
            dfs(heights, vis, rx, ry);
            
        }
    }
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> v;
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>atlantic(n, vector<int>(m,0));   
        vector<vector<int>>pacific(n, vector<int>(m,0));
        
        
        for(int i=0;i<n;i++){
            dfs(heights, pacific, i,0);
            dfs(heights, atlantic, i, m-1);
        }
        
        for(int i=0;i<m;i++){
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, n-1,i);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    
                    v.push_back(temp);
                }
            }
        }
        
        
        return v;
    }
};