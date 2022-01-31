class Solution {
public:
    bool check(int i,int j,int l,vector<vector<int>>& g){
        int n=g[i][j];
        for(int a=i;a<i+l;a++){
            for(int b=j;b<j+l;b++){
                if(g[a][b]!=n)return false;
            }
        }
        return true;
    }
    Node* construct(int i,int j,int l,vector<vector<int>>& grid){
        //cout<<i<<" "<<j<<" "<<l<<endl;
        if(l==1 || check(i,j,l,grid))return new Node(grid[i][j],1);
        l/=2;
        return new Node(1,0,construct(i,j,l,grid),construct(i,j+l,l,grid),construct(i+l,j,l,grid),construct(i+l,j+l,l,grid));
        
    }
    Node* construct(vector<vector<int>>& grid) {
        int l=grid.size();
        return construct(0,0,l,grid);
    }
};