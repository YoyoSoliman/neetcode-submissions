class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        int end = points[0][1];
        int arrows = points.size();

        //[1,4] [2,7] [3,9]
        for (int i = 1; i < points.size();i++) {
            if (end >= points[i][0]) {
                arrows--;
                end = min(end,points[i][1]);
            } else {
                end = points[i][1];
            }
        }

        return arrows;
    }
};
