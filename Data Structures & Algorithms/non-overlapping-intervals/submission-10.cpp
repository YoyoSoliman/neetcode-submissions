class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int currEnd = intervals[0][1];

        int count = 0;
        for (int i = 1; i < intervals.size();i++) {
            if (currEnd > intervals[i][0]) {
                count++;
                currEnd = min(currEnd,intervals[i][1]);
            } else {
                currEnd = intervals[i][1];
            }
        }

        return count;
    }
};
