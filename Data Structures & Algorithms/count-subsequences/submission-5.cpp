class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int i, int j,const string& s,const string& t) {

        if (j>=t.size()) {
            return 1;
        }

        if (i >= s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int choice1 = 0;
        if (s[i] == t[j]) {
            choice1 = dfs(i+1,j+1,s,t);
        }

        int choice2 = dfs(i+1,j,s,t);

        dp[i][j] = choice1 + choice2;

        return dp[i][j];

    }
    int numDistinct(string s, string t) {
        dp.assign(s.size(),vector<int>(t.size(),-1));
        return dfs(0,0,s,t);
    }
};
