class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

    std::queue<std::pair<int,int>> q;


    for (int y = 0; y < grid.size(); y++ ) {
        for (int x = 0; x < grid[0].size();x++) {
            if (grid[y][x] == 0) {
                q.push({x,y});
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();

        if (grid[y][x] != -1 || grid[y][x] == 2147483647) {
            if (y + 1 < grid.size() && grid[y+1][x] == 2147483647){
                grid[y+1][x] = grid[y][x] + 1;
                q.push({x,y+1});

            }
            if (x + 1 < grid[0].size() && grid[y][x+1] == 2147483647){
                grid[y][x+1] = grid[y][x] + 1;
                q.push({x+1,y});
            }

            if (x - 1 >= 0 && grid[y][x-1] == 2147483647){
                grid[y][x-1] = grid[y][x] + 1;
                q.push({x-1,y});
            }

            if (y - 1 >= 0 && grid[y-1][x] == 2147483647) {
                grid[y-1][x] = grid[y][x] + 1;
                q.push({x,y-1});
            }
        }
    }
    }
};
