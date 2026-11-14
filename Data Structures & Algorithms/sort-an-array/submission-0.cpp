class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res;
        priority_queue<int,vector<int>,greater<int>> min_heap;

        for (int n : nums) {
            min_heap.push(n);
        }

        while (!min_heap.empty()) {
            res.push_back(min_heap.top());
            min_heap.pop();
        }

        return res;

    }
};