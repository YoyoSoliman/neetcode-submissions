class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> numFreq;
        priority_queue<int> maxHeap;

        vector<int> res;

        for (int i = 0; i < k;i++) {
            numFreq[nums[i]]++;
            maxHeap.push(nums[i]);
        }

        res.push_back(maxHeap.top());

        int l = 0;
        int r = k;
        while (r < nums.size()) {
            numFreq[nums[l]]--;
            numFreq[nums[r]]++;
            maxHeap.push(nums[r]);

            while (!maxHeap.empty() &&numFreq[maxHeap.top()] <= 0) {
                maxHeap.pop();
            }

            res.push_back(maxHeap.top());
            r++;
            l++;

        }

        return res;
    }
};
