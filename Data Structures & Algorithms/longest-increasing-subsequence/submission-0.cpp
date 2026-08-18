class Solution {
public:
    vector<vector<int>> dp;

    int dfs(vector<int>& nums,int index, int prev_index) {
        if (index >= nums.size() ) {
            return 0;
        }

        if (dp[index][prev_index+1] != -1) {
            return dp[index][prev_index+1];
        }

        int skip = 0;
        skip = dfs(nums,index+1,prev_index);
        

        int take = 0;
        if (prev_index == -1 || nums[index] > nums[prev_index]) {
            take = 1 + dfs(nums, index + 1, index);
        }

        return dp[index][prev_index+1] = max(take,skip);

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));

        return dfs(nums,0,-1);
    }
};
