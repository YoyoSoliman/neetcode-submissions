class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_fruits = 0;
        queue<pair<int,int>> q;

        for (int r = 0; r < grid.size();r++) {
            for (int c = 0; c < grid[0].size();c++) {
                if (grid[r][c] == 2) {
                    q.push({r,c});
                }

                if(grid[r][c] == 1) {
                    fresh_fruits++;
                }
            }
        }

        if (fresh_fruits == 0) {
            return 0;
        }

        const vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        int days = -1;

        while (!q.empty()) {
            int qLen =q.size();
            for (int i = 0; i < qLen;i++) {
                int cR = q.front().first;
                int cC = q.front().second;
                q.pop();

                for (const auto& [dr,dc]:dir) {
                    int newR = dr + cR;
                    int newC = dc + cC;
                    if (newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid[0].size()) {
                        continue;
                    }

                    if (grid[newR][newC] == 1) {
                        fresh_fruits--;
                        grid[newR][newC] = 2;
                        q.push({newR,newC});
                    }
                }
            }

            days++;

        }

        if (fresh_fruits != 0) {
            return -1;
        }

        return days;

    }
};
