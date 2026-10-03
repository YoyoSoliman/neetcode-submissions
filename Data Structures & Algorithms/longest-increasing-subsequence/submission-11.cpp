class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        int m = 1;

        for (int i = 1; i < nums.size();i++) {
            dp[i] = 1;
            for (int j = 0 ; j < i;j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i],1 + dp[j]);
                }
            }
            m = max(m,dp[i]);
        }

        return m;
        
    }
};
