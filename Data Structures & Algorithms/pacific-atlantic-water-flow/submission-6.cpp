class Solution {
public:
    bool reachPacific = false;
    bool reachAtlantic = false;
    set<pair<int,int>> seen;
    void dfs(int r, int c,vector<vector<int>>& heights) {
        if ((reachPacific && reachAtlantic) || seen.count({r,c})) {
            return;
        }
        if (r == 0 || c == 0) {
            reachPacific = true;
        }

        if (c == heights[0].size() - 1 || r == heights.size()-1) {
            reachAtlantic = true;
        }

        seen.insert({r,c});

        if (r+1 < heights.size() && heights[r][c] >= heights[r+1][c]) {
            dfs(r+1,c,heights);
        }

        if (r-1 >= 0 && heights[r][c] >= heights[r-1][c]) {
            dfs(r-1,c,heights);
        }


        if (c+1 < heights[0].size() && heights[r][c] >= heights[r][c+1]) {
            dfs(r,c+1,heights);
        }


        if (c-1 >= 0 && heights[r][c] >= heights[r][c-1]) {
            dfs(r,c-1,heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        for (int r = 0; r < heights.size(); r++) {
            for (int c = 0; c < heights[0].size();c++) {
                reachPacific = false;
                reachAtlantic=false;
                seen.clear();

                dfs(r,c,heights);

                if (reachPacific && reachAtlantic) {
                    res.push_back({r,c});
                }

            }
        }

        return res;
    }
};
