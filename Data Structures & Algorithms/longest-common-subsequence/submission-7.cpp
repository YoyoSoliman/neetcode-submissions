class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() +1,0));
        for (int r = dp.size()-2;r >= 0; r--) {
            for (int c = dp[0].size()-2; c >= 0; c--) {
                if (text1[r] == text2[c]) {
                    dp[r][c] = 1 + dp[r+1][c+1];
                } else {
                    dp[r][c] = max(dp[r+1][c],dp[r][c+1]);
                }
            }
        }

        return dp[0][0];
    }
};
