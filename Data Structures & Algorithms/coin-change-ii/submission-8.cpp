class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int index, int currAmount,int amount,vector<int>& coins) {
        if (currAmount == amount) {
            return 1;
        }

        if (index >=coins.size() || currAmount > amount) {
            return 0;
        }

        if (dp[index][currAmount] != -1) {
            return dp[index][currAmount];
        }

        int choice1 = dfs(index,currAmount + coins[index],amount,coins);

        int choice2 = dfs(index+1,currAmount,amount,coins);

        dp[index][currAmount] = choice1 + choice2;

        return dp[index][currAmount];
    }
    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));

        return dfs(0,0,amount,coins);

    }
};
