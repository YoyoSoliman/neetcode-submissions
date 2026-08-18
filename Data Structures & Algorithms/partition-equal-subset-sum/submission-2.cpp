class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums,int sum1,int sum2, int index) {
        if (dp[sum1][sum2] != -1) {
            return dp[sum1][sum2];
        }

        if (index >= nums.size()) {
            if (sum1 == sum2) {
                return true;
            }
            return false;
        }

        if (dfs(nums,sum1 + nums[index],sum2,index+1) || dfs(nums,sum1,sum2 + nums[index],index+1)) {
            dp[sum1][sum2] = 1;
            return 1;
        } else {
            dp[sum1][sum2] = 0;
            return 0;
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0;i<nums.size();i++) {
            sum += nums[i];
        }
        dp.assign(sum+1, vector<int>(sum+1 + 1, -1));

        if (dfs(nums,0,0,0) == 1) {
            return true;
        } else {
            return false;
        }
    }
};
