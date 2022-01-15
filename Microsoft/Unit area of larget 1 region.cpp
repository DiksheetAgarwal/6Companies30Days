#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    int R[8]={0,1,1,1,0,-1,-1,-1};
    int C[8]={-1,-1,0,1,1,1,0,-1};
    
    int func(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&vis, int n, int m){
        
        vis[i][j]=1;
        int ans =0;
        for(int a=0;a<8;a++){
            int rs = i+R[a], ry = j+C[a];
            if(rs>=0 && rs<n && ry>=0 && ry<m && grid[rs][ry] == 1 && !vis[rs][ry])
                ans +=  func(grid, rs, ry, vis, n, m);
        }
        return 1+ans;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j])
                    count = max(count, func(grid,i,j,vis, n,m));
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends