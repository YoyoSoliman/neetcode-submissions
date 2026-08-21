class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,vector<int>& prices, int holding) {
        if (i >= prices.size()) {
            return 0;
        }

        if (dp[i][holding] != -1) {
            return dp[i][holding];
        }

        int choice = 0;
        //if we are hodlding we can either sell or continue to hold it
        if (holding) {
            choice = max(prices[i] + dfs(i+2,prices,0), dfs(i+1,prices,1));
        } else {
            choice = max(dfs(i+1,prices,1) - prices[i],dfs(i+1,prices,0));
        }

        dp[i][holding] = choice;
        return dp[i][holding];

    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(),vector<int>(2,-1));
        return dfs(0,prices,0);
    }
};
