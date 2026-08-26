class Solution {
public:

    set<vector<int>> seen;

    bool dfs(int i,int j, vector<vector<int>>& grid, int rainH) {

        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] > rainH || seen.count({i,j})) {
            return false;
        }

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return true;
        }

        seen.insert({i,j});


        return dfs(i+1,j, grid,rainH) || dfs(i-1,j, grid,rainH) || dfs(i,j-1, grid,rainH) || dfs(i,j+1, grid,rainH);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int maxElevation = INT_MIN;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0 ; i < rows;i++) {
            for(int j = 0; j < cols;j++) {
                maxElevation = max(maxElevation,grid[i][j]);
            }
        }

        int l = 0;
        int r = maxElevation;

        while (l < r) {
            seen.clear();
            int mid = l + ((r-l)/2);
            if (dfs(0,0,grid,mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;

    }
};
