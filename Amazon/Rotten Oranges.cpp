class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int ans=0, cnt=0;
        queue<pair<int, int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j] == 2)  q.push({i,j});
                if(grid[i][j]!=0) cnt++;
            }
        }
        int chk=0;
        int Xd[4]={-1,1,0,0};
        int Yd[4]={0,0,-1,1};
        while(!q.empty()){            
            int k = q.size();
            chk+= k;
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();                
                for(int i=0;i<4;i++){
                    int tx = x+Xd[i], ty = y+Yd[i];
                    if(tx<0 || ty<0 || tx>=grid.size() ||ty>=grid[0].size() || grid[tx][ty]!=1) continue;
                    grid[tx][ty] =2 ;
                    q.push({tx,ty});
                }                
            }
            if(!q.empty()) ans++;
        }
        return cnt == chk ? ans: -1;        
    }
};