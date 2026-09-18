class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int index, int currSum, vector<int>& coins, int target) {
        if (currSum == target) {
            return 1;
        }

        

        if (index >= coins.size() || currSum > target) {
            return 0;
        }

        if (dp[index][currSum] != -1) {
            return dp[index][currSum];
        }

        int choice1 = dfs(index,currSum + coins[index], coins,target);

        int choice2 = dfs(index+1,currSum,coins,target);

        dp[index][currSum] = choice1 + choice2;

        return dp[index][currSum];

    }
    int change(int amount, vector<int>& coins) {
        
        dp.assign(coins.size(), std::vector<int>(amount+1, -1));

        return dfs(0,0,coins,amount);

    }
};
