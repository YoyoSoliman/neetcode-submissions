class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequencyOfNumber;

        for (int n:nums) {
            frequencyOfNumber[n]++;
        }

        std::priority_queue<std::pair<int, int>> max_heap;

        for (const auto& [key, value]: frequencyOfNumber) {
            max_heap.push({value,key});
        }

        vector<int> res;

        for (int i = 0; i < k;i++) {
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }

        return res;

    }
};
