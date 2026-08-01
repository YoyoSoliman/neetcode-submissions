class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        std::sort(intervals.begin(),intervals.end());
        vector<int>prev = intervals[0];

        int count =0;


        for (int i = 1;i<intervals.size();i++) {
            if (prev[1] <= intervals[i][0]) {
                prev = intervals[i];
            } else {
                count++;
                prev[1] = min(prev[1], intervals[i][1]);
            }
        }

        return count;
    }
};
