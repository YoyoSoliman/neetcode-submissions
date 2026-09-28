class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int index, int hasCoin,vector<int>& prices) {

        if (index >= prices.size()) {
            return 0;
        }
        
        if (dp[index][hasCoin] != -1) {
            return dp[index][hasCoin];
        }

        //choice1: sell coin if we have it or but it if we dont have one
        int choice1 = 0;
        if (hasCoin == 1) {
            choice1 = prices[index] + dfs(index+2,0,prices);
        } else {
            choice1 = -prices[index] + dfs(index+1,1,prices);
        }

        int choice2 = dfs(index+1,hasCoin,prices);

        dp[index][hasCoin] = max(choice1,choice2);

        return dp[index][hasCoin];


    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(),vector<int>(2,-1));

        return dfs(0,0,prices);
    }
};
