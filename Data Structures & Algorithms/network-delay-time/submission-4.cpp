class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<vector<int>>> adjList;
        vector<int> minD(n+1,INT_MAX);
        minD[k]= 0;


        for (vector<int> t : times) {
            int u = t[0];
            int v = t[1];
            int d = t[2];

            adjList[u].push_back({t[2],t[1]});

        }

        std::priority_queue<std::pair<int, int>, 
                        std::vector<std::pair<int, int>>, 
                        std::greater<std::pair<int, int>>> minHeap;
        
        minHeap.push({0,k});


        while (!minHeap.empty()) {
            int d = minHeap.top().first;
            int node = minHeap.top().second;

            minHeap.pop();

            for (vector<int> children : adjList[node]) {
                int newD = children[0];
                int newN = children[1];

                if (d + newD < minD[newN]) {
                    minD[newN] = d + newD;
                    minHeap.push({minD[newN],newN});
                } 
            }


        }

        int res = INT_MIN;

        for (int i = 1;i < minD.size();i++) {
            if (minD[i] == INT_MAX) {
                return -1;
            }
            res = max(res,minD[i]);
        }

        return res;
    }
};
