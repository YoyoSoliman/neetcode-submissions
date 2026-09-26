class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));

        for (int r = m-2; r >=0; r--) {
            for (int c = n-2;c>=0;c--) {
                dp[r][c] = dp[r+1][c] + dp[r][c+1];
            }
        }

        return dp[0][0];


    }
};
