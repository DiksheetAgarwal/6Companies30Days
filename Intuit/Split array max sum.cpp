class Solution {
public:
    
    int dp[1001][51];
    
    int ff(vector<int>& nums, int m, int i) {
        
        if (i == nums.size() && m == 0) return 0;
        if (i == nums.size() || m == 0) return INT_MAX;
        if (dp[i][m] != -1) return dp[i][m];
        
        int final_ans = INT_MAX;
        
        for (int idx=i; idx < nums.size(); idx++) {
            int res = nums[idx] - ((i - 1 >= 0) ? nums[i - 1] : 0);
            int t = ff(nums, m - 1, idx + 1);
            final_ans = min(final_ans, max(res, t));
        }
        
        return dp[i][m] = final_ans;
    }
    
    int splitArray(vector<int>& nums, int m) {
        memset(dp, -1, sizeof dp);
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] == INT_MAX) return INT_MAX;
            nums[i] += (i - 1 >= 0) ? nums[i - 1] : 0;
        }
        return ff(nums, m, 0);
    }
};