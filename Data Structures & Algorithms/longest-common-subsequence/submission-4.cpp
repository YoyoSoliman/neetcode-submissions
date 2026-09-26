class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j,string text1, string text2) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int choice1=0;
        if (text1[i] == text2[j]) {
            choice1 = 1 + dfs(i+1,j+1,text1,text2);
        }

        int choice2 = dfs(i+1,j,text1,text2);

        int choice3 = dfs(i,j+1,text1,text2);

        dp[i][j] = max({choice1,choice2,choice3});

        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size(),vector<int>(text2.size(),-1));

        return dfs(0,0,text1,text2);
    }
};
