class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, std::vector<int>>> maxHeap;
        for (vector<int> point: points) {
            int x = point[0];
            int y = point[1];
            int dist = (x*x) + (y*y);

            maxHeap.push({dist,{x,y}});     
            while (maxHeap.size() > k) {
                maxHeap.pop();
            } 
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;

    }
};
