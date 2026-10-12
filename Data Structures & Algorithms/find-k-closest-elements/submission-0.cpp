class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::priority_queue<std::pair<int, int>> maxHeap;
        for (int i = 0; i < arr.size();i++) {
            maxHeap.push({std::abs(x-arr[i]),arr[i]});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        } 

        vector<int> res;

        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(res.begin(),res.end());

        return res;
    }
};