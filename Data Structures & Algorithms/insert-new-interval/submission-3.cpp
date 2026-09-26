class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        std::sort(intervals.begin(),intervals.end());

        vector<vector<int>> res;

        int i = 1;
        vector<int> curr = intervals[0]; 
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
