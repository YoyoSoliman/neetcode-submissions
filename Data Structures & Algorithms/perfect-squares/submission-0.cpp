#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int goal = 0; 
    std::vector<int> dp;

    int dfs(int amount) {
        if (amount == goal) {
            return 0;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }

        int m = INT_MAX;
        for (int i = 1; amount + i * i <= goal; i++) {
            int res = dfs(amount + i * i);
            if (res != INT_MAX) {
                m = std::min(m, res + 1);
            }
        }

        dp[amount] = m;
        return m;
    }

    int numSquares(int n) {
        goal = n;
        dp.assign(n + 1, -1);
        return dfs(0);
    }
};