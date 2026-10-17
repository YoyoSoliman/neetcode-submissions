//recurisve solution with cache
class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int currR,int currC,vector<vector<int>>& grid,int rows,int cols) {

        if (currR == rows-1 and currC == cols-1) {
            return grid[rows-1][cols-1];
        }

        if (dp[currR][currC] != -1) {
            return dp[currR][currC];
        }

        //choice 1: go down: 
        int choice1 = INT_MAX;

        if (currR + 1 < rows) {
            choice1 = dfs(currR + 1, currC, grid,rows,cols) + grid[currR][currC];
        }
        
        //choice 2 : do right
        int choice2 = INT_MAX;

        if (currC + 1 < cols) {
            choice2 = dfs(currR, currC + 1, grid,rows,cols) + grid[currR][currC];
        }

        dp[currR][currC] = min(choice1,choice2);

        return dp[currR][currC];
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.assign(grid.size(),vector<int>(grid[0].size(),-1));

        return dfs(0,0,grid,grid.size(),grid[0].size());
    }
};