class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int r, int c, int m, int n) {
        if (r == m-1 and c == n-1) {
            return 1;
        }

        if (r >= m || c >= n) {
            return 0;
        }

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        int goRight = dfs(r,c+1,m,n);
        int goDown = dfs(r+1,c,m,n);

        dp[r][c] = goRight + goDown;

        return dp[r][c];
    }
    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n,-1));
        return dfs(0,0,m,n);
    }   
};
