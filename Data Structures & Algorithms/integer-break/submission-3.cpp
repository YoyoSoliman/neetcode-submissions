class Solution {
public: 
    vector<int> dp;

    int dfs(int currSum) {
        if (currSum == 0) {
            return 1;
        }

        if (dp[currSum] != -1) {
            return dp[currSum];
        }

        int choice = INT_MIN; 
        for (int i = 1; i <= currSum;i++) {
            choice = max(choice, i * dfs(currSum-i));
        }

        dp[currSum] = choice;

        return dp[currSum];

    }
    int integerBreak(int n) {
        dp.assign(n+1,-1);
        
        if (n == 2) {
            return 1;
        }
        if (n==3) {
            return 2;
        }
        return dfs(n);        
    }
};