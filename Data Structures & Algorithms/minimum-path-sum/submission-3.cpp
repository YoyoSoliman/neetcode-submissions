//true dp solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        int rows = grid.size();
        int cols = grid[0].size();
        dp.assign(grid.size(),vector<int>(grid[0].size(),0));

        dp[rows-1][cols-1] = grid[rows-1][cols-1];

        for (int i = rows-2; i >= 0;i--) {
            dp[i][cols-1] = grid[i][cols-1] + dp[i+1][cols-1];
        }  

        for (int i = cols-2; i >=0;i-- ) {
            dp[rows-1][i] = grid[rows-1][i] + dp[rows-1][i+1];
        } 

        for (int r = rows-2;r >= 0;r--) {
            for (int c = cols-2;c >= 0 ;c--) {
                dp[r][c] = min(dp[r+1][c],dp[r][c+1]) + grid[r][c];
            }
        }

        return dp[0][0];
    }
};