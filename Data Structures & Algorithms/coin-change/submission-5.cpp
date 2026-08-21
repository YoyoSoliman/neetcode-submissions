class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,amount + 1);

        dp[amount] = 0;

        for (int i = amount; i>=0;i--) {
            if (dp[i] != amount+1) {
                for (int coin : coins) {
                    if (i-coin >= 0) {
                        dp[i-coin] = min(dp[i-coin], dp[i]+1);
                    }
                }
            }
        }

        if (dp[0]==amount+1) {
            return -1;
        } else {
            return dp[0];
        }
    }
};
