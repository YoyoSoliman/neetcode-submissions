class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>> maxHeap;
        for (int i = 0; i < points.size();i++) {
            vector<int> point = points[i];
            int x = point[0];
            int y = point[1];
            int d = (x*x) + (y*y);
            maxHeap.push({d,i});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return res;
    }
};
