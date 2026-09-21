class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for (int i = 0; i < grid.size();i++) {
            for (int j = 0; j < grid[0].size();j++) {
                if (grid[i][j] == 0) {
                    q.push({i,j});
                } 
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r + 1 < grid.size() && grid[r+1][c] == 2147483647) {
                grid[r+1][c] = grid[r][c] + 1;
                q.push({r+1,c});
            }
            
            if (r - 1 >= 0 && grid[r-1][c] == 2147483647) {
                grid[r-1][c] = grid[r][c] + 1;
                q.push({r-1,c});
            }

            if (c - 1 >= 0 && grid[r][c-1] == 2147483647) {
                grid[r][c-1] = grid[r][c] + 1;
                q.push({r,c-1});
            }

            if (c + 1 <grid[0].size() && grid[r][c+1] == 2147483647) {
                grid[r][c+1] = grid[r][c] + 1;
                q.push({r,c+1});
            }

        }

    }
};
