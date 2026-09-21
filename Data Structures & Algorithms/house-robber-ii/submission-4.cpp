class Solution {
public:
    vector<int> dp;

    int dfs(int index, int end, vector<int>& nums) {
        if (index >= end) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        //choice 1:
        int choice1 = nums[index] + dfs(index+2,end,nums);

        //choice 2:
        int choice2 = dfs(index+1,end,nums);

        dp[index] = max(choice1,choice2);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        dp.assign(nums.size(),-1);
        int c1 = dfs(0,nums.size()-1,nums);
        fill(dp.begin(),dp.end(),-1);

        int c2 = dfs(1,nums.size(),nums);

        return max(c1,c2);

    }
};
