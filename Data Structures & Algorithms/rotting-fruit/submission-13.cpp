class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int number_of_fresh_fruits = 0;
        queue<pair<int,int>> q;

        for (int r = 0; r < grid.size();r++) {
            for (int c = 0; c < grid[0].size();c++) {
                if (grid[r][c] == 1) {
                    number_of_fresh_fruits++;
                }
                if (grid[r][c] == 2) {
                    q.push({r,c});
                    grid[r][c] = 1;
                    number_of_fresh_fruits++;
                }
            }
        }

        if (number_of_fresh_fruits == 0) {
            return 0;
        }

        int days = -1;
        const vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
        while (!q.empty() and number_of_fresh_fruits > 0) {
            int qLen = q.size();

            for (int i = 0; i < qLen;i++) {
                int current_row = q.front().first;
                int current_col = q.front().second;
                q.pop();
                if (current_row < 0 || current_row >= grid.size() || current_col < 0 || current_col >= grid[0].size()||grid[current_row][current_col] == 2 ||grid[current_row][current_col] == 0) {
                    continue;
                }

                //spread
                grid[current_row][current_col] = 2;
                number_of_fresh_fruits--;

                for (const auto& [dr,dc] : dirs) {
                    q.push({current_row+dr,current_col+dc});
                }
            }
            days++;
        }

        if (number_of_fresh_fruits != 0) {
            return -1;
        }

        return days;
    }
};
