class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        queue<int> q;
        q.push(0);
        int count = 0;

        while (!q.empty()) {
            int qLen = q.size();
            count++;

            for (int i = 0; i < qLen; i++) {
                int c = q.front();
                for (int coin:coins) {
                    if (c + coin < dp.size() && dp[c+coin]==-1) {
                        dp[c+coin] = count;
                        q.push(c+coin);
                    }
                }
                q.pop();
            }

        }

        return dp[amount];
    }
};
