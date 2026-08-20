class Solution {
public:
    vector<int> dp;

    int dfs(int i,int goal) {

        if (i >= goal) {
            if (i==goal) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        //choice one take one step
        int oneStep = dfs(i+1,goal);

        int twoSteps = dfs(i+2,goal);

        dp[i] = oneStep + twoSteps;
        return dp[i];

    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return dfs(0,n);
    }
};
