class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r>=grid.size() || c >= grid[0].size()|| grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0;

        int left = dfs(r,c-1,grid);
        int right = dfs(r,c+1,grid);
        int up = dfs(r-1,c,grid);
        int down = dfs(r+1,c,grid);

        return left+right+up+down + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = 0;
        for (int r = 0; r < grid.size();r++) {
            for (int c = 0; c < grid[0].size();c++) {
                if (grid[r][c] == 1) {
                    m = max(m,dfs(r,c,grid));
                }
            }
        }
        return m;
    }
};
