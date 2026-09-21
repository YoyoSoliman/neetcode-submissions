class Solution {
public:
    vector<int> dp;
    int dfs(int index,vector<int>& nums) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        //choice 1: 
        int choice1 = nums[index] + dfs(index+2,nums);

        //choice 2:
        int choice2 = dfs(index+1,nums);

        dp[index] = max(choice1,choice2);

        return dp[index];

    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return dfs(0,nums);
    }
};
