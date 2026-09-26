class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());

        vector<int> curr = intervals[0];
        int i = 1;
        while (i < intervals.size()) {
            if (curr[1] >= intervals[i][0]) {
                curr[0] = min(curr[0],intervals[i][0]);
                curr[1] = max(curr[1],intervals[i][1]);
            } else {
                res.push_back(curr);
                curr = intervals[i];
            }
            i++;
        }

        res.push_back(curr);

        return res;
    }
};
