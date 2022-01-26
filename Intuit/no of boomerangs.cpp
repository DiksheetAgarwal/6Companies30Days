class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            unordered_map<int, int>v(n);
            for(int j=0;j<n;j++){
                int dis = (points[i][1]- points[j][1])*(points[i][1]- points[j][1]) + abs(points[i][0] - points[j][0])* abs(points[i][0] - points[j][0]);
                // if(v[i].find(dis) == v[i].end())  v[i][dis] = 1;
                 v[dis]++;
            }
            for(auto x:v){
                if(x.second>1)
                    ans+= (x.second)*(x.second-1);
            }
            
        }
    
        
        return ans;
        
        
    }
};