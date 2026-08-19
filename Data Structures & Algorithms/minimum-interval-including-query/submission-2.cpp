class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        
        std::priority_queue<
            std::pair<int, std::vector<int>>,
            std::vector<std::pair<int, std::vector<int>>>,
            std::greater<std::pair<int, std::vector<int>>>
        > min_heap;

        sort(intervals.begin(), intervals.end());

        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        unordered_map<int, int> queryToResult;

        int i = 0;
        int n = intervals.size();

        for (int q : sortedQueries) {
            while (i < n && intervals[i][0] <= q) {
                int len = intervals[i][1] - intervals[i][0] + 1;
                min_heap.push({len, intervals[i]});
                i++;
            }

            while (!min_heap.empty() && min_heap.top().second[1] < q) {
                min_heap.pop();
            }

            if (min_heap.empty()) {
                queryToResult[q] = -1;
            } else {
                queryToResult[q] = min_heap.top().first;
            }
        }

        for (int q : queries) {
            res.push_back(queryToResult[q]);
        }

        return res;
    }
};