class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int index, int currSum, vector<int>& nums,int target) {
        if (currSum > target) {
            return 0;
        }

        if (index >= nums.size()) {
            if (currSum == target) {
                return 1;
            } else {
                return 0;
            }
        } 

        if (dp[index][currSum] != -1) {
            return dp[index][currSum];
        }

        //choice1 take it:
        int choice1 = dfs(index+1,currSum + nums[index],nums,target);

        //choice2
        int choice2 = dfs(index+1,currSum,nums,target);

        dp[index][currSum] = choice1 || choice2;

        return dp[index][currSum];
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int n : nums) {
            total+=n;
        }

        if (total % 2 == 1) {
            return false;
        }

        int target = total/2;

        dp.assign(nums.size(),vector<int>(target+1,-1));

        return dfs(0,0,nums,target);
    }
};
