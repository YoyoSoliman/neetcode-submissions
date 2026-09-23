class Solution {
public:
    vector<int> dp;

    int dfs(int curr, int amount,vector<int>& coins) {
        if (curr == amount) {
            return 0;
        }

        if (curr > amount) {
            return INT_MAX;
        }

        if (dp[curr] != -1) {

            return dp[curr];
        }

        int minCoinsNeeded = INT_MAX;
        for (int n : coins) {
            if (n <= amount && curr + n <= amount) {
                int c = dfs(curr+n,amount,coins);
                if (c!= INT_MAX) {
                    minCoinsNeeded = min(minCoinsNeeded, c + 1);
                }
            }
        }

        dp[curr] = minCoinsNeeded;

        return dp[curr];
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount+1,-1);

        int res = dfs(0,amount,coins);

        if (res == INT_MAX) {
            return -1;
        }

        return res;
    }
};
