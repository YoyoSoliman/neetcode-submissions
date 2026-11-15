class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int n : stones) {
            maxHeap.push(n);
        }

        while (maxHeap.size() > 1) {

            int firstStone = maxHeap.top();
            maxHeap.pop();

            int secondStone = maxHeap.top();
            maxHeap.pop();

            if (firstStone > secondStone) {
                maxHeap.push(firstStone - secondStone);
            }

        }

        if (maxHeap.empty()) {
            return 0;
        }

        return maxHeap.top();
    }
};
