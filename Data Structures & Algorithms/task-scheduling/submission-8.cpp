class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> task_freq;

        for (char c: tasks) {
            task_freq[c]++;
        }

        priority_queue<int> max_heap;
        queue<pair<int,int>> q;

        for (const auto& [key,value]: task_freq) {
            max_heap.push(value);
        }

        int cycle = 0;

        while (!q.empty() || !max_heap.empty()) {
            if (max_heap.empty()) {
                cycle = q.front().first;
                max_heap.push(q.front().second);
                q.pop();
                continue;
            }

            if (!q.empty() and cycle >= q.front().first) {
                max_heap.push(q.front().second);
                q.pop();
            }

            int curr_task_count = max_heap.top();
            max_heap.pop();

            if (curr_task_count > 1) {
                q.push({cycle + n + 1,curr_task_count-1});
            }

            cycle++;
        }

        return cycle;



    }
};
