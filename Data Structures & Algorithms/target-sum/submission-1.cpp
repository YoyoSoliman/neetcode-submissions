class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (abs(target) > totalSum) return 0;

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * totalSum + 1, 0));

        dp[0][totalSum] = 1;

        for (int i = 0; i < n; i++) {
            for (int s = -totalSum; s <= totalSum; s++) {
                if (dp[i][s + totalSum] > 0) {
                    dp[i + 1][s + nums[i] + totalSum] += dp[i][s + totalSum];
                    dp[i + 1][s - nums[i] + totalSum] += dp[i][s + totalSum];
                }
            }
        }

        return dp[n][target + totalSum];
    }
};