class Solution {
public:
    int maxArea = 0;
    int currArea;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size();x++) {
                if (grid[y][x] == 1) {
                    currArea = 0;
                    dfs(grid,y,x);
                    maxArea = max(currArea,maxArea);
                }
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid,int y, int x) {

        currArea++;
        grid[y][x] = 2;

        //go right
        if (x + 1 < grid[0].size() && grid[y][x+1] == 1) {
            dfs(grid,y,x+1);
        }


        //go left
        if (x -1 >= 0 && grid[y][x-1] == 1) {
            dfs(grid,y,x-1);
        }
        
        //go down
        if (y + 1 < grid.size() && grid[y+1][x] == 1) {
            dfs(grid,y+1,x);
        }


        //go down
        if (y - 1 >= 0 && grid[y-1][x] == 1) {
            dfs(grid,y-1,x);

        }

    }
};
