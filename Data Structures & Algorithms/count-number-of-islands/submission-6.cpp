class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1}, {0,-1}};

    void dfs(int r, int c, vector<vector<char>>& grid) {
        if (r < 0 || c < 0 || r >=grid.size() || c >=grid[0].size()||grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';

        for (const auto& [dr,dc]:dirs) {
            dfs(r + dr, c + dc,grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for (int r = 0 ; r < grid.size();r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    res++;
                    dfs(r,c,grid);
                }
            }
        }

        return res;
    }
};
