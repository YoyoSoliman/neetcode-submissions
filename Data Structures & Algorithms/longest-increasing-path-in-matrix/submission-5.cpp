class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int r, int c, vector<vector<int>>& matrix) {
        
        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        //choice1 go up if possible:
        int choice1 = 1;
        if (r-1 >= 0 && matrix[r][c] < matrix[r-1][c]) {
            choice1 = 1 + dfs(r-1,c,matrix);
        }

        // go down
        int choice2 = 1;
        if (r+1 < matrix.size() && matrix[r][c] < matrix[r+1][c]) {
            choice2 = 1 + dfs(r+1,c,matrix);
        }

        // go right
        int choice3 = 1;
        if (c+1 < matrix[0].size() && matrix[r][c] < matrix[r][c+1]) {
            choice3 = 1 + dfs(r,c+1,matrix);
        }

        // go left
        int choice4 = 1;
        if (c-1 >= 0 && matrix[r][c] < matrix[r][c-1]) {
            choice4 = 1 + dfs(r,c-1,matrix);
        }

        dp[r][c] = max({choice1,choice2,choice3,choice4});

        return dp[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.assign(matrix.size(),vector<int>(matrix[0].size(),-1));
        int res = 1;

        for (int r = 0; r < matrix.size();r++) {
            for (int c = 0; c < matrix[0].size();c++) {
                res = max(res,dfs(r,c,matrix));
            }
        }

        return res;
    }
};
