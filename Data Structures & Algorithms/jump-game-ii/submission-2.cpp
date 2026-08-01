class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),1000000);
        dp[0] = 0;

        for (int i = 0; i < nums.size();i++) {
            if (dp[i] < 1000000) {
                int nextStep = dp[i] + 1;
                for (int k = 1; k < nums[i]+1;k++) {
                    if ((i+k < nums.size()) && (dp[i+k] > nextStep)) {
                        dp[i+k] = nextStep;
                    }
                }
            }
        }

        return dp[nums.size()-1];
    }
};
