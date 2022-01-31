class Solution {
public:
    int func(vector<int>&v, int start, int end, vector<vector<int>>&dp){
        if(start>end)
            return 0;
        if(dp[start][end]!= -1)    return dp[start][end];       
        int left = v[start] + min(func(v, start+2, end,dp), func(v, start+1, end-1,dp));
        int right = v[end] + min(func(v, start,end-2,dp), func(v, start+1, end-1,dp));
        
        return dp[start][end] = max(left, right);
        
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        int ans = func(piles, 0, piles.size()-1, dp);
        return ans;
    }
};