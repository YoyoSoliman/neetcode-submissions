class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        
        // Min-heap storing {length, interval_vector} to match your original pair structure
        std::priority_queue<
            std::pair<int, std::vector<int>>,
            std::vector<std::pair<int, std::vector<int>>>,
            std::greater<std::pair<int, std::vector<int>>>
        > min_heap;

        // 1. Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // 2. Keep queries in sorted order to avoid re-pushing elements back into the heap
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        // Map to store query results so we can return them in the original query order
        unordered_map<int, int> queryToResult;

        int i = 0;
        int n = intervals.size();

        for (int q : sortedQueries) {
            // Add all valid intervals that start before or at q
            while (i < n && intervals[i][0] <= q) {
                int len = intervals[i][1] - intervals[i][0] + 1;
                min_heap.push({len, intervals[i]});
                i++;
            }

            // Remove invalid intervals that end before q (they will never match future queries either)
            while (!min_heap.empty() && min_heap.top().second[1] < q) {
                min_heap.pop();
            }

            // The top of the heap is now guaranteed to be the shortest valid interval
            if (min_heap.empty()) {
                queryToResult[q] = -1;
            } else {
                queryToResult[q] = min_heap.top().first;
            }
        }

        // 3. Populate results in original query order
        for (int q : queries) {
            res.push_back(queryToResult[q]);
        }

        return res;
    }
};