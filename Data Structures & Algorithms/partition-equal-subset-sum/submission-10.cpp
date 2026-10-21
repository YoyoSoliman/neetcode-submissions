class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int index, int currSum,int target,vector<int>& nums) {
        if (currSum > target) {
            return 0;
        }
        if (index >= nums.size()) {
            if (currSum == target) {
                return 1;
            }
            return 0;
        }

        if(dp[index][currSum] != -1) {
            return dp[index][currSum];
        }

        int choice1 = dfs(index+1,currSum + nums[index], target,nums);

        int choice2 = dfs(index+1,currSum, target,nums);

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

        dp.assign(nums.size(),vector<int>((totalSum/2) + 1,-1));

        return dfs(0,0,totalSum/2,nums);


    }
};
