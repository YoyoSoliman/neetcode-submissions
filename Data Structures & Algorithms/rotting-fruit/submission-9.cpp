class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        int totalFreshFruit = 0;

        for (int r = 0; r < grid.size();r++) {
            for (int c = 0; c < grid[0].size();c++) {

                if (grid[r][c] == 2) {
                    q.push({r,c});
                }

                if (grid[r][c] == 1) {
                    totalFreshFruit++;
                }

            }
        }
        
        if (totalFreshFruit == 0) {
            return 0;
        }

        int days = -1;
        while (!q.empty()) {
            int qLen = q.size();

            for (int i = 0; i < qLen;i++) {
                int currR = q.front().first;
                int currC = q.front().second;
                q.pop();

                if (currR + 1 < grid.size() && grid[currR + 1][currC] == 1 ) {
                    q.push({currR+1,currC});
                    grid[currR+1][currC] = 2;
                    totalFreshFruit--;
                }


                if (currR - 1 >= 0 && grid[currR - 1][currC] == 1 ) {
                    q.push({currR-1,currC});
                    grid[currR-1][currC] = 2;
                    totalFreshFruit--;

                }


                if (currC + 1 < grid[0].size() && grid[currR][currC + 1] == 1 ) {
                    q.push({currR,currC + 1});
                    grid[currR][currC + 1] = 2;
                    totalFreshFruit--;

                }


                if (currC - 1 >= 0 && grid[currR][currC - 1] == 1 ) {
                    q.push({currR,currC - 1});
                    grid[currR][currC - 1] = 2;
                    totalFreshFruit--;

                }
            }
            days++;
        }

        if (totalFreshFruit > 0) {
            return -1;
        }

        return days;
    }
};
