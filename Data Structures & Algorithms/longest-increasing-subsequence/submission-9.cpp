class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int index, int lastIndex, vector<int>& nums) {

        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index][lastIndex + 1]!=-1) {
            return dp[index][lastIndex + 1];
        }

        //choice 1 : add this num to the sequence:
        int choice1 = 0;
        if (lastIndex == -1 || nums[index] > nums[lastIndex]){
            choice1 = 1 + dfs(index+1,index,nums);
        }

        //choice 2: skip to next index;

        int choice2 = dfs(index+1,lastIndex,nums);

        dp[index][lastIndex + 1] = max(choice2,choice1);

        return dp[index][lastIndex + 1];

    }
    int lengthOfLIS(vector<int>& nums) {

        dp.assign(nums.size(),vector<int>(nums.size() + 1,-1));

        return dfs(0,-1,nums);


    }
};
