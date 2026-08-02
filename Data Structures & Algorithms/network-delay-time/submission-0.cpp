class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> rep(n+1);
        for (const auto& time: times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];

            rep[u].push_back({v,t});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;

        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        //distance,node
        minHeap.push({dist[k], k});

        while (!minHeap.empty()){
            auto [time,node] = minHeap.top();
            minHeap.pop();

            if (time > dist[node]) {
                continue;
            }

            for (const auto& edge : rep[node]) {
                int v = edge.first;
                int t = edge.second;

                if (dist[node] + t < dist[v]) {
                    dist[v] = dist[node] + t;
                    minHeap.push({dist[v],v});
                }

            }
        }

        int m = 0;
        for (int i = 1; i<dist.size();i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            m = max(m,dist[i]);
        }

        return m;

    }
};
