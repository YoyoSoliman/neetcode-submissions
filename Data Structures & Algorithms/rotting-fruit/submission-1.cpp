class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshFruits = 0;
        int days = -1;

        int turnedFreshFruits = 0;
        //holds rotten fruits
        std::queue<std::pair<int,int>> q;

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == 2) {
                    q.push({y,x});
                }
                if (grid[y][x] == 1) {
                    freshFruits++;
                }
            }

        }

        if (freshFruits == 0){
            return 0;
        }

        while (!q.empty()) {
            int qLen = q.size();
            for (int i = 0; i < qLen; i++) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                if (y + 1 < grid.size() && grid[y+1][x] == 1){
                    grid[y+1][x] = 2;
                    q.push({y+1,x});
                    turnedFreshFruits++;
                }


                if (y - 1 >= 0 && grid[y-1][x] == 1){
                    grid[y-1][x] = 2;
                    q.push({y-1,x});
                    turnedFreshFruits++;
                }


                if (x + 1 < grid[0].size() && grid[y][x + 1] == 1){
                    grid[y][x + 1] = 2;
                    q.push({y,x + 1});
                    turnedFreshFruits++;
                }


                if (x - 1 >= 0 && grid[y][x - 1] == 1){
                    grid[y][x - 1] = 2;
                    q.push({y,x - 1});
                    turnedFreshFruits++;
                }

            }
            days++;

        }

        if (freshFruits != turnedFreshFruits){
            return -1;
        } else {
           return days;
        }



    }
};
