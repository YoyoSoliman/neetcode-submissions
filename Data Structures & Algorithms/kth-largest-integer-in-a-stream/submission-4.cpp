#include <queue>
#include <vector>

class KthLargest {
public:

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k;
    vector<int> nums;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;

        for (int j = 0; j < nums.size(); j++) {
            minHeap.push(nums[j]);
        }

        while (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        while (minHeap.size() > k) {
            minHeap.pop();

        }

        return minHeap.top();

    }
};
