class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> canReachPacific(heights.size(), vector<int>(heights[0].size(),0));
        vector<vector<int>> canReachAtlantic(heights.size(), vector<int>(heights[0].size(),0));

        queue<pair<int,int>> q;

        for (int i = 0; i <canReachPacific[0].size();i++) {
            canReachPacific[0][i] = 1;
            q.push({0,i});
        }

        for (int i = 0; i < canReachPacific.size();i++) {
            canReachPacific[i][0] = 1;
            q.push({i,0});
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r + 1 < canReachPacific.size() && heights[r][c] <= heights[r+1][c] && canReachPacific[r+1][c] == 0) {
                q.push({r+1,c});
                canReachPacific[r+1][c] = 1;        
            }

            if (r - 1 >= 0 && heights[r][c] <= heights[r-1][c] && canReachPacific[r-1][c] == 0) {
                q.push({r-1,c});
                canReachPacific[r-1][c] = 1;  
            }


            if (c + 1 < canReachPacific[0].size() && heights[r][c] <= heights[r][c+1] && canReachPacific[r][c+1] == 0) {
                q.push({r,c+1});
                canReachPacific[r][c+1] = 1;
            }


            if (c - 1 >= 0 && heights[r][c] <= heights[r][c-1] && canReachPacific[r][c-1] == 0) {
                q.push({r,c-1});
                canReachPacific[r][c-1] = 1;
            }
        }


        for (int i = 0; i <canReachAtlantic[0].size();i++) {
            canReachAtlantic[canReachAtlantic.size()-1][i] = 1;
            q.push({canReachAtlantic.size()-1,i});
        }

        for (int i = 0; i < canReachAtlantic.size();i++) {
            canReachAtlantic[i][canReachAtlantic[0].size()-1] = 1;
            q.push({i,canReachAtlantic[0].size()-1});
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r + 1 < canReachAtlantic.size() && heights[r][c] <= heights[r+1][c] && canReachAtlantic[r+1][c] == 0) {
                q.push({r+1,c});
                canReachAtlantic[r+1][c] = 1;        
            }

            if (r - 1 >= 0 && heights[r][c] <= heights[r-1][c] && canReachAtlantic[r-1][c] == 0) {
                q.push({r-1,c});
                canReachAtlantic[r-1][c] = 1;  
            }


            if (c + 1 < canReachAtlantic[0].size() && heights[r][c] <= heights[r][c+1] && canReachAtlantic[r][c+1] == 0) {
                q.push({r,c+1});
                canReachAtlantic[r][c+1] = 1;
            }


            if (c - 1 >= 0 && heights[r][c] <= heights[r][c-1] && canReachAtlantic[r][c-1] == 0) {
                q.push({r,c-1});
                canReachAtlantic[r][c-1] = 1;
            }
        }

        vector<vector<int>> res;

        for (int r = 0; r < heights.size();r++) {
            for (int c = 0; c < heights[0].size();c++) {
                if (canReachPacific[r][c] == 1 && canReachAtlantic[r][c] == 1) {
                    res.push_back({r,c});
                }
            }
        }

        return res;


    }
};
