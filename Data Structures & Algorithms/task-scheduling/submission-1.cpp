class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<int> maxHeap;
        
        queue<pair<int,int>> q;
        unordered_map<char,int> m;

        for (char task:tasks) {
            m[task]++;
        }

        for (const auto& [key,value]: m) {
            maxHeap.push(value);
        }

        int cycle = 0;

        while (!maxHeap.empty() || !q.empty()) {
            while(!q.empty() && q.front().first <= cycle) {
                maxHeap.push(q.front().second);
                q.pop();
            }

            if (maxHeap.empty()) {
                cycle++;
                continue;
            }

            int amount = maxHeap.top();

            maxHeap.pop();

            if (amount > 1) {
                q.push({cycle + n + 1,amount-1});
            }

            cycle++;

        }
        

        return cycle;
    }
};
