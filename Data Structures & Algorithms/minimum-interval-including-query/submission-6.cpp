class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> qwi;

        for (int i = 0; i < queries.size();i++) {
            qwi.push_back({queries[i],i});
        }   

        sort(qwi.begin(),qwi.end());

        int end = -1;

        for (int n : queries) {
            end = max(end,n);
        }

        std::priority_queue<
        std::pair<int, int>, 
        std::vector<std::pair<int, int>>, 
        std::greater<std::pair<int, int>>
         > minHeap;

        vector<int> res(qwi.size(),-1);

        reverse(intervals.begin(),intervals.end());

        
        for (int i = 0 ; i < qwi.size();i++ ) {
            int n = qwi[i].first;
            int index = qwi[i].second;
            while (!intervals.empty() && n>=intervals.back()[0]) {
                minHeap.push({intervals.back()[1] - intervals.back()[0] + 1, intervals.back()[1]}) ;
                intervals.pop_back();
            }

            while (!minHeap.empty() && n > minHeap.top().second) {
                minHeap.pop();
            }

        
            if (!minHeap.empty()) {
                res[index] = minHeap.top().first;
            }
        }

        return res;

    }
};
