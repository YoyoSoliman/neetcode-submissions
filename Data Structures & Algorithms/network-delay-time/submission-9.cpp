class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> minDistances(n+1,INT_MAX);

        unordered_map<int,vector<pair<int,int>>> adjList;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (vector<int> time:times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];

            adjList[u].push_back({t,v});
        }

        minHeap.push({0,k});

        while (!minHeap.empty()) {
            auto[time,dest_node] = minHeap.top();
            minHeap.pop();
            if (minDistances[dest_node] <= time) {
                continue;
            }

            minDistances[dest_node] = time;

            for (const auto& [newT,new_node]: adjList[dest_node]) {
                if (minDistances[new_node] > newT + time) {
                    minHeap.push({newT + time, new_node});
                }
            }
        }

        int m = 0;

        for (int i = 1; i < minDistances.size();i++) {
            m = max(minDistances[i],m);
        }

        if (m==INT_MAX) {
            return -1;
        }
        return m;



    }
};
