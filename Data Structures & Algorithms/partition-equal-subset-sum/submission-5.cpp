class Solution {
public:
    vector<vector<int>> dp;
    int targetSum = 0;
    int dfs(int index, int currSum,vector<int>& nums) {
        if (currSum == targetSum) {
            return 1;
        }

        if (currSum > targetSum) {
            return 0;
        }

        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index][currSum] != -1) {
            return dp[index][currSum];
        }

        //choice 1 put in first bucket:
        int choice1 = dfs(index+1,currSum + nums[index],nums);

        int choice2 = dfs(index+1,currSum,nums);

        dp[index][currSum] = choice1 || choice2;

        return dp[index][currSum];

    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        for (int n : nums) {
            totalSum +=n;
        }

        if (totalSum % 2 == 1) {
            return false;
        }

        targetSum = totalSum / 2;

        dp.assign(nums.size(),vector<int>(targetSum + 1 , -1));

        return dfs(0,0,nums);
    }
};
