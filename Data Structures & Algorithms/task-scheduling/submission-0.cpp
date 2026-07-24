#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        int cycles = 0;

        std::unordered_map<char,int> count;
        std::priority_queue<int> maxHeap;
        std::queue<std::pair<int,int>> q;

        for (int i = 0; i < tasks.size(); i++) {
            count[tasks[i]]++;
        }

        for (const auto& [key, value] : count) {
            maxHeap.push(value);
        }

        while (!maxHeap.empty() || !q.empty()) {
            cycles++;

            if (!maxHeap.empty()) {
                int val = maxHeap.top();
                maxHeap.pop();
                if (val - 1 > 0) {
                    q.push({val - 1, cycles + n});
                }
            } 

            if (!q.empty() && q.front().second <= cycles) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        
        return cycles;
    }
};