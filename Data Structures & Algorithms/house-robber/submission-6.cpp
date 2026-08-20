class Solution {
public:
    vector<int> dp;
    int dfs(int i, vector<int>& nums) {
        if (i>=nums.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        //Choice one:rob first house and skip the next one
        int r1 = nums[i] + dfs(i+2,nums);

        //Choice 2: dont rob the first house and go to the next one
        int r2 = dfs(i+1,nums);

        dp[i] = max(r1,r2);

        return dp[i];
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size(),-1);

        return dfs(0,nums);
    }
};
