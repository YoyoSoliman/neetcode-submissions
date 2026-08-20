class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j,int m,int n) {

        if ((i == m-1) && (j == n-1)) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        } 

        //choice 1:go down if possible
        int down = 0;
        if (i + 1<m) {
            down = dfs(i+1,j,m,n);
        }

        //choice 2: go right if possible
        int right = 0;
        if (j+1 < n) {
            right = dfs(i,j+1,m,n);
        }

        dp[i][j] = down + right;

        return dp[i][j];


    }
    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n,-1));

        return dfs(0,0,m,n);

    }
};
