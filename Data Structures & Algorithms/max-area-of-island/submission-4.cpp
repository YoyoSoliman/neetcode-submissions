class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>& grid ) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;

        int left = dfs(r,c-1,grid);
        int right = dfs(r,c+1,grid);
        int up = dfs(r-1,c,grid);
        int down =dfs(r+1,c,grid);

        return left + right + up + down + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size();i++) {
            for (int j = 0; j < grid[0].size();j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea,dfs(i,j,grid));
                }
            }
        }

        return maxArea;
    }
};
