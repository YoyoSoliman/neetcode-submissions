class Solution {
public:
    const vector<pair<int,int>> dirs {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r,int c,int lastH,vector<vector<int>>& grid,vector<vector<int>>& heights) {
        if (r < 0 || c < 0 || r >=grid.size() || c >= grid[0].size() || grid[r][c] == 1 || heights[r][c] < lastH) {
            return;
        }

        grid[r][c] = 1;

        for (const auto& [dr,dc]:dirs) {
            int newR = dr + r;
            int newC = dc + c;
            dfs(newR,newC,heights[r][c],grid,heights);
        }


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> canReachP(rows,vector<int>(cols,0));
        vector<vector<int>> canReachA(rows,vector<int>(cols,0));

        for (int i = 0;i < cols;i++) {
            dfs(0,i,-1,canReachP,heights);
        }

        for (int i = 0; i < rows;i++) {
            dfs(i,0,-1,canReachP,heights);
        }

        for (int i = 0;i < rows;i++) {
            dfs(i,cols-1,-1,canReachA,heights);
        }

        for (int i = 0; i < cols;i++) {
            dfs(rows-1,i,-1,canReachA,heights);
        }

        vector<vector<int>> res;
        for (int r = 0; r < rows;r++) {
            for (int c = 0; c < cols;c++) {
                if (canReachA[r][c]==1 and canReachP[r][c]==1) {
                    res.push_back({r,c});
                }
            }
        }

        return res;

    }
};
