class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int r, int c, vector<vector<int>>& grid) {

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        if (r == grid.size()-1 and c == grid[0].size()-1) {
            return grid[r][c];
        }

        int right = INT_MAX;
        if (c + 1 < grid[0].size()) {
            right = dfs(r,c+1,grid);
        }


        int down = INT_MAX;
        if (r + 1 < grid.size()) {
            down = dfs(r+1,c,grid);
        }

        dp[r][c] = min(right,down) + grid[r][c];

        return dp[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.assign(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(0,0,grid);
    }
};