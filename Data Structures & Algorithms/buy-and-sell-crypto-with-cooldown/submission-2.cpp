#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   
    vector<vector<int>> dp;

    int dfs(vector<int>& prices, int index, int buying) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp[index][buying] != -1) {
            return dp[index][buying];
        }

        if (buying == 1) {
            int buy = dfs(prices, index + 1, 0) - prices[index];
            int cooldown = dfs(prices, index + 1, 1);
            dp[index][buying] = max(buy, cooldown);
        } else {
            int sell = dfs(prices, index + 2, 1) + prices[index];
            int cooldown = dfs(prices, index + 1, 0); 
            dp[index][buying] = max(sell, cooldown);
        }

        return dp[index][buying];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return dfs(prices, 0, 1);
    }
};