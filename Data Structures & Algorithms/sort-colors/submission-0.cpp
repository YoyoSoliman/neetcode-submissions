class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> min_heap;

        for (int n : nums) {
            min_heap.push(n);
        }
        int i = 0;

        while (!min_heap.empty()) {
            nums[i] = min_heap.top();
            min_heap.pop();
            i++;
        }
    }
};