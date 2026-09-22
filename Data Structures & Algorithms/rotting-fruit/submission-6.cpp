class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totalFreshFruit = 0;
        queue<vector<int>> q;
        for (int i = 0 ; i < grid.size();i++) {
            for (int j = 0; j < grid[0].size();j++) {
                if (grid[i][j] == 1) {
                    totalFreshFruit++;
                }
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        if (totalFreshFruit == 0) {
            return 0;
        }
        int days = 0;

        while (!q.empty()) {
            int qLen = q.size();

            for (int i = 0;i < qLen;i++) {
                int r = q.front()[0];
                int c = q.front()[1];
                q.pop();



                if (r+1 < grid.size() && grid[r+1][c] == 1) {
                    q.push({r+1,c});
                    grid[r+1][c] = 2;
                    totalFreshFruit--;
                }
                if (r-1 >= 0 && grid[r-1][c] == 1) {
                    q.push({r-1,c});
                    grid[r-1][c] = 2;
                    totalFreshFruit--;

                }
                if (c+1 < grid[0].size() && grid[r][c+1] == 1) {
                    q.push({r,c+1});
                    grid[r][c+1] = 2;
                    totalFreshFruit--;

                }
                if (c-1 >= 0 && grid[r][c-1] == 1) {
                    q.push({r,c-1});
                    grid[r][c-1] = 2;
                    totalFreshFruit--;

                }
            }
            days++;
        }

        if (totalFreshFruit == 0) {
            return days - 1;
        }

        return -1;
    }
};
