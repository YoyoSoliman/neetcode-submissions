class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int day, int hasCoin,vector<int>& prices) {
        if (day >= prices.size()) {
            return 0;
        }

        if (dp[day][hasCoin] != -1) {
            return dp[day][hasCoin];
        }

        // Choice 1: Take coin if we don't have one
        int choice1=0;
        if (hasCoin == 0) {
            choice1 = dfs(day+1,1,prices) - prices[day];
        }

        //choice 2: sell coin if we have it
        int choice2 = 0;
        if (hasCoin == 1) {
            choice2 = dfs(day+1,0,prices) + prices[day];
        }

        int choice3 = dfs(day+1,hasCoin,prices);

        dp[day][hasCoin] = max({choice1,choice2,choice3});
        return dp[day][hasCoin];
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(),vector<int>(2,-1));

        return dfs(0,0,prices);
    }
};