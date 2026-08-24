class Solution {
public:
    int perimeter = 0;
    set<pair<int,int>> seen;

    void dfs(int y,int x,vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size() || grid[y][x] == 0) {
            perimeter++;
            return;
        }
        
        seen.insert({y,x});

        if (!seen.count({y,x+1})) {
            dfs(y,x+1,grid);
        }

        if (!seen.count({y,x-1})) {
            dfs(y,x-1,grid);
        }

        if (!seen.count({y+1,x})) {
            dfs(y + 1,x,grid);
        }

        if (!seen.count({y-1,x})) {
            dfs(y-1,x,grid);
        }


    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size();i++) {
            for (int j = 0; j < grid[0].size();j++) {
                if (grid[i][j] == 1) {
                    dfs(i,j,grid);
                    return perimeter;
                }
            }
        }

        return 0;
    }
};