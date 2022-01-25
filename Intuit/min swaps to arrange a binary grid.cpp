class Solution {
public:
    void swap(int *a, int*b){
        int x = *a;
        *a = *b;
        *b = x;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] == 1){
                    v.push_back(j);
                    break;
                }
            }
            if(v.size()!= i+1)  v.push_back(0);
        }
        vector<int> temp;
        temp = v;
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++){
            if(v[i]>i)
                return -1;
        }
        
        v = temp;
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(v[i]>i){
                int j=i;
                while(v[j]>i)   j++;
                
                while(j>i){
                    cnt++;
                    swap(&v[j], &v[j-1]);
                    j--;
                }
            }
        }
        
        return cnt;
        
    }
};