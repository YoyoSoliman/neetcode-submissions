class Solution {
public:
    bool loop = false;
    vector<int> states;
    unordered_map<int,vector<int>> adjList;

    void dfs(int curr, int father) {

        if (loop) {
            return;
        }

        if (states[curr] == 2) {
            return;
        }

        if (states[curr] == 1) {
            loop = true;
            return;
        }

        states[curr] = 1;

        for (int n : adjList[curr]) {
            if (n != father) {
                dfs(n,curr);
            }
        }

        states[curr] = 2;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if (n - 1 !=edges.size()) {
            return false;
        }

        states.assign(n,0);

        for (vector<int> edge : edges) {
            adjList[edge[0]].push_back(edge[1]);

            adjList[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n;i++) {
            dfs(i,-1);
            if (loop) {
                return false;
            }

        }

        return true;
    }
};
