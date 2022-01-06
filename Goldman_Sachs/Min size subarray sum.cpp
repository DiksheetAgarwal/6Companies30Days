class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e8;
        
        int l =0;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            
            while(sum>= target){
                ans = min(ans, i-l+1);
                sum-= nums[l];
                l++;
            }
        }
        
        if(ans == 1e8)
            ans=0;
        
        return ans;
    }
};