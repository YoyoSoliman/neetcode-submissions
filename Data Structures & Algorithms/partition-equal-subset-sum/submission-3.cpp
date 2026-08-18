class Solution {
public:
    vector<vector<int>> memo;

    bool dfs(vector<int>& nums, int index, int target) {
        if (target == 0) return true;  
        if (index >= nums.size() || target < 0) return false;

        if (memo[index][target] != -1) {
            return memo[index][target];
        }

        bool include = dfs(nums, index + 1, target - nums[index]);
        bool exclude = dfs(nums, index + 1, target);

        return memo[index][target] = (include || exclude);
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        memo.assign(n, vector<int>(target + 1, -1));

        return dfs(nums, 0, target);
    }
};