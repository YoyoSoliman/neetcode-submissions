class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int i,int j,string s,string t) {

        if (j==t.size()) {
            return 1;
        }

        if (i >= s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        //choice 1:skip the character at s
        int w = dfs(i+1,j,s,t);

        //choice 2: if they match move both indecies
        if (s[i] == t[j]) {
            w += dfs(i+1,j+1,s,t);
        }
        dp[i][j] = w;
        return dp[i][j];


    }
    int numDistinct(string s, string t) {
        dp.assign(s.size(),vector<int>(t.size(),-1));

        return dfs(0,0,s,t);
    }
};
