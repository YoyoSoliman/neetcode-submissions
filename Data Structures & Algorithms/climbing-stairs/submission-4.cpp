class Solution {
public:
    vector<int> dp;
    int dfs(int step,int goal) {
        if (step == goal) {
            return 1;
        }
        
        if (step > goal) {
            return 0;
        }

        if (dp[step] != -1) {
            return dp[step];
        }

        //choice 1: take one step
        int choice1 = dfs(step+1,goal);

        //choice 2 : take two steps
        int choice2 = dfs(step+2,goal);

        dp[step] = choice1 + choice2;
        return dp[step];
    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return dfs(0,n);
    }
};
