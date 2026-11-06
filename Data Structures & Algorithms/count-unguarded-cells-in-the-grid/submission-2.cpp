// guards = 1;
// wall = 2;
// guard_vision = 3;
// empty = 0;
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));

        for (vector<int> wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }

        for (vector<int> guard : guards) {
            int curr_r = guard[0];
            int curr_c = guard[1];
            grid[curr_r][curr_c] = 1;

            int i = 1;
            while (curr_r + i < grid.size() and  grid[curr_r + i][curr_c] != 2 and grid[curr_r + i][curr_c] != 1 ) {
                grid[curr_r + i][curr_c] = 3;
                i++;
            }

            i = -1;
            while (curr_r + i >= 0 and grid[curr_r + i][curr_c] != 2 and grid[curr_r + i][curr_c] != 1) {
                grid[curr_r + i][curr_c] = 3;
                i--;
            }

            i = 1;
            while (curr_c + i < grid[0].size() and grid[curr_r][curr_c + i] != 2 and grid[curr_r][curr_c + i] != 1) {
                grid[curr_r][curr_c + i] = 3;
                i++;
            }

            i = -1;
            while (curr_c + i >= 0 and grid[curr_r][curr_c + i] != 2 and grid[curr_r][curr_c + i] != 1) {
                grid[curr_r][curr_c + i] = 3;
                i--;
            }
        }

        int res = 0;

        for (int r = 0 ; r <grid.size();r++) {
            for (int c = 0; c < grid[0].size();c++) {
                if (grid[r][c] == 0) {
                    res++;
                }
            }
        }
        return res;
        
    }
};
