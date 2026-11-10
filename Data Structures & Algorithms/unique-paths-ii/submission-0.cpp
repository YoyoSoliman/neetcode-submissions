class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int r, int c, vector<vector<int>>& obstacleGrid) {
        if (r < 0 || c < 0 || r >= obstacleGrid.size() || c >= obstacleGrid[0].size() || obstacleGrid[r][c] == 1) {
            return 0;
        }

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        if (r == obstacleGrid.size()-1 and c == obstacleGrid[0].size()-1) {
            return 1;
        }

        int right = dfs(r,c+1,obstacleGrid);
        int down = dfs(r+1,c,obstacleGrid);

        dp[r][c] = right + down;
        return dp[r][c];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        dp.assign(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));

        return dfs(0,0,obstacleGrid);
    }
};