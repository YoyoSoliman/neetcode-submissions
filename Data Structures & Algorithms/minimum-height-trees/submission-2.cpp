class Solution {
public:
    map<int,vector<int>> adjList;

    int dfs(int node,int father) {
        
        int maxHeight = 0;

        for (int child : adjList[node]) {
            if (child != father) {
                maxHeight = max(dfs(child,node),maxHeight);
            }
        }

        return 1 + maxHeight;

    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.empty()) {
            return {0};
        }

        for (vector<int> edge:edges ) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        std::priority_queue<std::pair<int, int>, 
                        std::vector<std::pair<int, int>>, 
                        std::greater<std::pair<int, int>>> min_heap;


        for (int i = 0; i < n;i++) {
            int h = dfs(i,-1);
            min_heap.push({h,i});
        }

        int min = min_heap.top().first;
        vector<int> res;
        while (!min_heap.empty() && min_heap.top().first == min) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return res;


    }
};