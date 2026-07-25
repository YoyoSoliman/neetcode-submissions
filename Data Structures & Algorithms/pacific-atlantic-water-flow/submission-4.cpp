class Solution {
public:
    void dfs(int y,int x,vector<vector<int>>& heights,vector<vector<bool>>& ocean){
        if (y < 0 || x < 0 || y >= heights.size()|| x >= heights[0].size()) {
            return;
        }

        if (ocean[y][x] == true) {
            return;
        }


        ocean[y][x] = true;

        if (y+1 < heights.size() && heights[y][x] <= heights[y+1][x]) {
            dfs(y+1,x,heights,ocean);
        }


        if (y-1 >= 0 && heights[y][x] <= heights[y-1][x]) {
            dfs(y-1,x,heights,ocean);
        }

        if (x + 1 < heights[0].size() && heights[y][x] <= heights[y][x+1]) {
            dfs(y,x+1,heights,ocean);
        }


        if (x - 1 >= 0 && heights[y][x] <= heights[y][x-1]) {
            dfs(y,x-1,heights,ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> res;

        std::vector<std::vector<bool>> reachPacific(row, std::vector<bool>(col, false));
        std::vector<std::vector<bool>> reachAtlantic(row, std::vector<bool>(col, false));


        //start from spots touching pacific ocean:
        for (int x = 0; x < col; x++) {
            dfs(0,x,heights,reachPacific);
        }
        for (int y = 0; y < row; y++) {
            dfs(y,0,heights,reachPacific);
        }

        //starts form spots that touch atalantic
        for (int x = 0; x < col; x++) {
            dfs(row-1,x,heights,reachAtlantic);
        }
        for (int y = 0; y < row; y++) {
            dfs(y,col-1,heights,reachAtlantic);
        }

        for (int y = 0; y < row; y++){
            for (int x = 0; x < col;x++){
                if (reachPacific[y][x] && reachAtlantic[y][x]) {
                    res.push_back({y,x});
                }
            }

        }

        return res;
    }
};
