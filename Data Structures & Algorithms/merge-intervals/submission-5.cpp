class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<int> currInterval = intervals[0];

        int i = 1;

        vector<vector<int>> res;

        while (i < intervals.size()) {
            if (currInterval[1] >= intervals[i][0]) {
                currInterval[0] = min(currInterval[0],intervals[i][0]);
                currInterval[1] = max(currInterval[1],intervals[i][1]);
            } else {
                res.push_back(currInterval);
                currInterval = intervals[i];
            }
            i++;
        }

        res.push_back(currInterval);

        return res;
    }
};
