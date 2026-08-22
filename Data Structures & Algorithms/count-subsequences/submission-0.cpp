class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int i,int j,string s,string t) {
        if (i >= s.size() || j >= t.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        //choice1
        int choice1 = 0;
        if (s[i] == t[j]) {
            if (j == t.size()-1) { 
                choice1 = 1 + dfs(i+1,j+1,s,t);
            } else {
                choice1 = dfs(i+1,j+1,s,t);
            }
        }

        int choice2 = 0;
        choice2 = dfs(i+1,j,s,t);

        dp[i][j] = choice1 + choice2;

        return dp[i][j];


    }
    int numDistinct(string s, string t) {
        dp.assign(s.size(),vector<int>(t.size(),-1));

        return dfs(0,0,s,t);
    }
};
