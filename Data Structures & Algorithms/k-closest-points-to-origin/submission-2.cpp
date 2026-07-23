class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        std::priority_queue<std::pair<int, int>, 
                        std::vector<std::pair<int, int>>, 
                        std::greater<std::pair<int, int>>> minHeap;

        for (int i = 0; i < points.size();i++) {
            int dist = (points[i][0]* points[i][0]) + (points[i][1] * points[i][1]);
            minHeap.push({dist,i});
        }

        for (int i = 0; i < k; i++) {
            std::pair<int, int> topElement = minHeap.top();
            res.push_back(points[topElement.second]);
            minHeap.pop();
        }

        return res;



    }
};
