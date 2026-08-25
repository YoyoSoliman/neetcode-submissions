class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //vector with minimum path for each one
        vector<int> minPath(n+1,INT_MAX);

        unordered_map<int,vector<pair<int,int>>> adjList;

        for (vector<int> time:times) {
            adjList[time[0]].push_back({time[2],time[1]});
        }

        minPath[k] = 0;

        std::priority_queue<
        std::pair<int, int>, 
        std::vector<std::pair<int, int>>, 
        std::greater<std::pair<int, int>>
    > minHeap;

        minHeap.push({0,k});

        while (!minHeap.empty()) {

            int node = minHeap.top().second;
            int time = minHeap.top().first;
            minHeap.pop();

            if (time > minPath[node]) {
                continue; 
            }

            for (pair<int,int> children:adjList[node]) {
                int n = children.second;
                int t = children.first;

                if (time + t < minPath[n]) {
                    minPath[n] = time + t;
                    minHeap.push({minPath[n],n});

                }
            }
        }

        int m = -1;

        for (int i = 1; i < minPath.size();i++) {
            m = max(m,minPath[i]);
        }


        if (m == INT_MAX) {
            return -1;
        }

        return m;




    }
};
