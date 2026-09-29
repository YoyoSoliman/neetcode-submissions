class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int r, int c,int prev, vector<vector<int>>& matrix) {
        if (r < 0|| r >= matrix.size() || c < 0|| c >= matrix[0].size() || matrix[r][c] == -1) {
            return 0;
        }

        if (matrix[r][c] <= prev) {
            return 0;
        }

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        int tmp = matrix[r][c];
        matrix[r][c] = -1;

        int choice1 = 1 + dfs(r+1,c,tmp,matrix);
        int choice2 = 1 + dfs(r-1,c,tmp,matrix);
        int choice3 = 1 + dfs(r,c+1,tmp,matrix);
        int choice4 = 1 + dfs(r,c-1,tmp,matrix);

        matrix[r][c] = tmp;
        dp[r][c] = max({choice1,choice2,choice3,choice4});

        return dp[r][c];


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.assign(matrix.size(),vector<int>(matrix[0].size(),-1));
        int m = 0;

        for (int r = 0 ; r < matrix.size();r++) {
            for (int c=0;c < matrix[0].size();c++) {
                m = max(m,dfs(r,c,-1,matrix));
            }
        }
        return m;
    }
};
