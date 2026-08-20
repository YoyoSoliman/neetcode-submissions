class Solution {
public:
    vector<int> dp;
    int dfs(int i,vector<int>& nums, int end) {
        if (i >= end) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int r1 = nums[i] + dfs(i+2,nums,end);
        int r2 = dfs(i+1,nums,end);

        dp[i] = max(r1,r2);
        return dp[i];
    }   
    int rob(vector<int>& nums) {
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        dp.assign(nums.size(),-1);
        int choice1 = dfs(0,nums,nums.size()-1);

        dp.assign(nums.size(),-1);
        int choice2 = dfs(1,nums,nums.size());

        return max(choice1,choice2);
    }
};
