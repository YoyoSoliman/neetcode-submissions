class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> max_heap;
        queue<pair<int,int>> q;

        unordered_map<char,int> task_to_count;
        for (char c : tasks) {
            task_to_count[c]++;
        }

        for (const auto& [key,value] : task_to_count) {
            max_heap.push(value);
        }

        int curr_cycle = 0;

        while (!max_heap.empty() or !q.empty()) {
            while (!q.empty() and q.front().first < curr_cycle) {
                max_heap.push(q.front().second);
                q.pop();
            }

            if (max_heap.empty()) {
                curr_cycle++;
                continue;
            }

            int k = max_heap.top();
            max_heap.pop();

            if (k > 1) {
                q.push({curr_cycle + n, k-1});
            }

            curr_cycle++;

        }

        return curr_cycle;

    }
};
