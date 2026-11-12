class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for (int r = 0; r < grid.size();r++) {
            for (int c = 0; c < grid[0].size();c++) {
                if (grid[r][c] == 0) {
                    q.push({r,c});
                }
            }
        }

        const vector<pair<int,int>> dirs {{1,0},{-1,0},{0,1},{0,-1}};
        int days = 0;
        
        while (!q.empty()) {
            int qlen=q.size();
            for (int i = 0; i < qlen;i++) {
                int curr_r = q.front().first;
                int curr_c = q.front().second;
                q.pop();

                for (const auto& [dr,dc] : dirs) {
                    int newR = dr + curr_r;
                    int newC = dc + curr_c;

                    if (newR < 0 || newC < 0 || newR >= grid.size()|| newC >= grid[0].size() || grid[newR][newC]!=2147483647) {
                        continue;
                    }
                    grid[newR][newC] = days + 1;
                    q.push({newR,newC});
                }


            }

            days++;
        }
    }
};
