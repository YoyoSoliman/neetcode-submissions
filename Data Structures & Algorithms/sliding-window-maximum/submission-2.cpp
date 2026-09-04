class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> numberCount;
        std::priority_queue<int> maxHeap;
        for (int i = 0; i < k;i++) {
            numberCount[nums[i]]++;
            maxHeap.push(nums[i]);
        }

        res.push_back(maxHeap.top());
        int l = 0;
        int r = k;

        while (r < nums.size()) {
            numberCount[nums[r]]++;
            maxHeap.push(nums[r]);
            numberCount[nums[l]]--;

            while (numberCount[maxHeap.top()] <= 0) {
                maxHeap.pop();
            }

            res.push_back(maxHeap.top());

            r++;
            l++;
        }

        return res;
    }
};
