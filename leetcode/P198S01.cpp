class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int dp[len];
        for(int i=0;i<len;++i) {
            if(i == 0)
                dp[0] = nums[0];
            else if(i == 1)
                dp[1] = max(nums[1],dp[0]);
            else
                dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[len-1];
    }
};
