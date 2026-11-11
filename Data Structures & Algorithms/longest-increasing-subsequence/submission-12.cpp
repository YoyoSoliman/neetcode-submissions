class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int curr_index,int last_index, vector<int>& nums) {
        if (curr_index >= nums.size()) {
            return 0;
        }

        if (dp[curr_index+1][last_index+1] != -1) {
            return dp[curr_index+1][last_index+1];
        }

        //choice 1 take the curr_index and move on;
        int choice1 = 0;
        if (last_index == -1|| nums[curr_index] > nums[last_index]) {
            choice1 = dfs(curr_index+1,curr_index,nums) + 1;
        }
        //choice 2: dont take it and continue;

        int choice2 = dfs(curr_index+1,last_index,nums);

        dp[curr_index+1][last_index+1] = max(choice1,choice2);

        return dp[curr_index+1][last_index+1];
        
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size()+1, vector<int>(nums.size()+1,-1));

        return dfs(0,-1,nums);
    }
};
