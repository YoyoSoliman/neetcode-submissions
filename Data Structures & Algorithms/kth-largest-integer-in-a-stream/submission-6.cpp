class KthLargest {
public:
    priority_queue<int> maxHeap;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for (int n : nums) {
            maxHeap.push(n);
        }
    }
    
    int add(int val) {
        maxHeap.push(val);
        vector<int> removedItems;

        for (int i = 0; i < kth - 1;i++) {
            removedItems.push_back(maxHeap.top());
            maxHeap.pop();
        }

        int res = maxHeap.top();

        for (int n : removedItems) {
            maxHeap.push(n);
        }

        return res;


    }
};
