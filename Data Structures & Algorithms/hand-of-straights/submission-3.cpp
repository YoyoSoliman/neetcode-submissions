class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> intCount;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int n : hand) {
            if (!intCount.count(n)) {
                minHeap.push(n);
            }

            intCount[n]++;
        }

        while (!minHeap.empty()) {
            while(!minHeap.empty() && intCount[minHeap.top()] <= 0) {
                minHeap.pop();
            }
            if (minHeap.empty()) {
                return true;
            }

            int start = minHeap.top();

            for (int i = start;i < start+groupSize;i++) {
                if (!intCount.count(i) || intCount[i] <= 0) {
                    return false;
                }
                intCount[i]--;
            }
        }

        return true;
    }
};
