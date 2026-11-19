class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end());

        vector<int> curr_interval = {intervals[0][0],intervals[0][1]};
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size();i++) {
            if (curr_interval[1] >= intervals[i][0]) {
                curr_interval[0] = min(curr_interval[0],intervals[i][0]);
                curr_interval[1] = max(curr_interval[1],intervals[i][1]);
            } else {
                res.push_back(curr_interval);
                curr_interval = intervals[i];
            }
        }

        res.push_back(curr_interval);

        return res;
    }
};
