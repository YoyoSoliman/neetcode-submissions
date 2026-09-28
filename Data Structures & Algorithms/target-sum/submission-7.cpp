class Solution {
public:
    int totalSum = 0;
    vector<vector<int>> dp;

    int dfs(int index, int currAmount,int goal,vector<int>& nums) {

        if (index >= nums.size()) {
            if (currAmount == goal) {
                return 1;
            }
            return 0;
        }

        if (dp[index][currAmount + totalSum] != -1) {
            return dp[index][currAmount+totalSum];
        }

        int choice1 = dfs(index+1, currAmount + nums[index],goal,nums);
        int choice2 = dfs(index+1, currAmount - nums[index],goal,nums);

        dp[index][currAmount + totalSum] = choice1+choice2;

        return dp[index][currAmount + totalSum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {


        for (int n : nums) {
            totalSum += n;
        }
        int cols = (totalSum * 2) + 1;
        dp.assign(nums.size(),vector<int>(cols,-1));

        return dfs(0,0,target,nums);
    }
};
