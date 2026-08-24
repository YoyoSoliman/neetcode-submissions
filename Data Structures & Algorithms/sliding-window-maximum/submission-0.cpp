class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
    priority_queue<int> maxHeap;
    map<int,int> numberCount;
    vector<int> res;

    for (int i = 0; i < k; i++) {
        maxHeap.push(nums[i]);
        numberCount[nums[i]]++;
    }
    res.push_back(maxHeap.top());

    int l = 0;
    int r = k;

    while (r < nums.size()) {

        maxHeap.push(nums[r]);
        numberCount[nums[r]]++;
        numberCount[nums[l]]--;


        while (!numberCount.count(maxHeap.top()) || numberCount[maxHeap.top()] <= 0 ) {
            maxHeap.pop();
        }

        res.push_back(maxHeap.top());

        l++;
        r++;
    }

    return res;

    }
};
