class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int index,vector<int>& nums,int prevIndex) {
        if (index >= nums.size()) {
            return 0;
        }

      
        if (dp[index][prevIndex + 1] != -1) {
                return dp[index][prevIndex + 1];
            }

        int choice1 = 0;

        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            choice1 = dfs(index+1,nums,index) + 1;
        }

        int choice2 = dfs(index+1,nums,prevIndex);

        dp[index][prevIndex + 1] = max(choice1,choice2);

        return dp[index][prevIndex +1];
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size(),vector<int>(nums.size() + 1,-1));

        return dfs(0,nums,-1);
        
    }
};
