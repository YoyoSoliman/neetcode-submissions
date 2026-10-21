class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count_tasks;
        priority_queue<int> maxHeap;

        for (char c : tasks) {
            count_tasks[c]++;
        }

        for (const auto& [key,value]: count_tasks) {
            maxHeap.push(value);
        }

        //<day,freq>
        queue<pair<int,int>> q;

        int count = 0;

        while (!maxHeap.empty() || !q.empty()) {
            while (!q.empty() && q.front().first <= count) {
                maxHeap.push(q.front().second);
                q.pop();
            }
            
            if (maxHeap.empty()) {
                count++;
                continue;
            }

            int num = maxHeap.top();
            maxHeap.pop();

            if (num == 1) {
                count++;
                continue;
            }

            q.push({count+n+1,num-1});
            count++;
        }

        return count;
    }
};
