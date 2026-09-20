class Solution {
public:
    vector<int> dp;
    int dfs(int index,vector<int>& cost) {
        if (index >= cost.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        //choice 1: take 1 step
        int choice1 = dfs(index+1,cost) + cost[index]; 

        //choice 2: take 2 steps
        int choice2 = dfs(index+2,cost) + cost[index]; 

        dp[index] = min(choice1,choice2);

        return dp[index];


    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size() + 1,-1);
        return min(dfs(0,cost),dfs(1,cost));
    }
};
