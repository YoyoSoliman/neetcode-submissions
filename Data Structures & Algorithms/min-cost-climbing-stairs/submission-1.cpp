class Solution {
public:
    vector<int> dp;
    int dfs(int i, vector<int>& cost) {
        if (i >= cost.size()) {
            return 0;
        } 

        if (dp[i] != -1) {
            return dp[i];
        }

        //choice 1: take one step
        int oneStep = cost[i] + dfs(i+1,cost);
        int twoSteps = cost[i] + dfs(i+2,cost);

        dp[i] = min(oneStep,twoSteps);

        return min(oneStep,twoSteps);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size() + 1,-1);

        return min(dfs(0,cost),dfs(1,cost));
    }
};
