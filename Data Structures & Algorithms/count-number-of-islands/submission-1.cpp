class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
       for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size();x++) {
                if (grid[y][x] == '1') {
                    res++;
                    dfs(grid,x,y);
                }

            }

       } 

       return res;
    }

    void dfs(vector<vector<char>>& grid,int x, int y) {
        grid[y][x] = 'A';
        //go right
        if (x + 1 < grid[0].size() && grid[y][x+1] == '1') {
            dfs(grid,x+1,y);
        }

        //go up
        if (y-1 >= 0 && grid[y-1][x] == '1') {
            dfs(grid,x,y-1);
        }

        //go left
        if(x-1 >= 0 && grid[y][x-1] == '1') {
            dfs(grid,x-1,y);
        }

        //go down
        if (y+1 < grid.size() && grid[y+1][x] == '1'){
            dfs(grid,x,y+1);

        }
    }
};
