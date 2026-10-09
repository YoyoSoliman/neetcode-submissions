class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        std::priority_queue<
            std::pair<int, int>, 
            std::vector<std::pair<int, int>>, 
            std::greater<std::pair<int, int>>
            > min_heap;

        vector<pair<vector<int>,int>> newTasks;
        for (int i = 0; i < tasks.size();i++){
            newTasks.push_back({tasks[i],i});
        }

        std::sort(newTasks.begin(),newTasks.end());
        reverse(newTasks.begin(),newTasks.end());
        vector<int> res;

        int time = newTasks[newTasks.size()-1].first[0];

        while (!newTasks.empty() || !min_heap.empty()) {
            while (!newTasks.empty() && time >= newTasks.back().first[0]) {
                min_heap.push({newTasks.back().first[1],newTasks.back().second});
                newTasks.pop_back();
            }

            if (min_heap.empty()) {
                time = newTasks.back().first[0];
            } else {
                res.push_back(min_heap.top().second);
                time += min_heap.top().first;
                min_heap.pop();
            }

       }

       return res;

    }
};