class Solution {
public:
    vector<int> states;
    unordered_map<int,vector<int>> adjList;

    void dfs(int curr) {
        if (states[curr] == 1) {
            return;
        }

        states[curr] = 1;

        for (int n : adjList[curr]) {
            if (states[n] == 0) {
                dfs(n);
            }
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for (vector<int> edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        states.assign(n,0);

        int count = 0;
        for (int i = 0; i < n;i++ ) {
            if (states[i] == 0) {
                dfs(i);
                count++;
            }
        }

        return count;
    }
};
