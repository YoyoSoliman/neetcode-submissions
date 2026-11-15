class KthLargest {
public:

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;

        for (int n : nums) {
            minHeap.push(n);
        }


    }
    
    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > kth) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
