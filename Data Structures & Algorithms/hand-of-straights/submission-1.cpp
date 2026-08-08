class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int,int> m;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        unordered_set<int> seen;

        for (int h: hand) {
            m[h]++;
            if (!seen.count(h)) {
                minHeap.push(h);
                seen.insert(h);
            }
        }

        while (!minHeap.empty()) {
            while (!minHeap.empty() && m[minHeap.top()] <= 0) {
                minHeap.pop();
            }

            if (minHeap.empty()) {
                break;
            }

            int start = minHeap.top();

            for (int i = start; i < minHeap.top()+groupSize;i++) {
                if (!seen.count(i) || m[i] <= 0) {
                    return false;
                }
                m[i]--;
            }
        }

        return true;
         


    }
};
