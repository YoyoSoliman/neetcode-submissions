class Solution {
public:
    vector<vector<int>> canReachP;
    vector<vector<int>> canReachC;

    const vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(int r, int c,int prevV, vector<vector<int>>& grid,vector<vector<int>>& values) {
        if (r >= grid.size()|| c >= grid[0].size() || r < 0 || c < 0 || grid[r][c] == 1 || prevV > values[r][c]) {
            return;
        }

        grid[r][c] = 1;

        for (auto [dr,dc] : dirs) {

            int nr = r + dr;
            int nc = c + dc;
            dfs(nr,nc,values[r][c],grid,values);

        }


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        canReachP.assign(rows,vector<int>(cols,0));
        canReachC.assign(rows,vector<int>(cols,0));

        for (int i = 0 ; i < canReachP.size();i++) {
            dfs(i,0,-1,canReachP,heights);
        }

        for (int i = 0; i < canReachP[0].size();i++) {
            dfs(0,i,-1,canReachP,heights);
        }

        for (int i = 0; i < canReachC[0].size();i++) {
            dfs(canReachC.size()-1,i,-1, canReachC,heights);
        }

        for (int i = 0; i < canReachC.size();i++) {
            dfs(i,canReachC[0].size()-1,-1,canReachC,heights);
        }

        vector<vector<int>> res;

        for (int r = 0; r < heights.size();r++) {
            for (int c = 0; c < heights[0].size();c++) {
                if (canReachC[r][c] == 1 and canReachP[r][c] == 1) {
                    res.push_back({r,c});
                }
            }
        }

        return res;

    }
};
