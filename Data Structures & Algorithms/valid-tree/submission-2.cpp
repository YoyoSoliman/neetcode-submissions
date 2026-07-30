class Solution {
public:
    std::unordered_set<int> visited;
    std::unordered_map<int,vector<int>> connections;
    int count = 0;

    bool dfs(int curr, int parent) {
        count++;
        if (connections[curr].empty()) {
            return false;
        }
        if (visited.contains(curr)) {
            return false;
        }

        if ((connections[curr].size() == 1 && connections[curr][0] == parent)) {
            return true;
        }

        visited.insert(curr);

        for (int child: connections[curr]) {
            if (child != parent) {
                if (!dfs(child,curr)) {
                    return false;
                }
            }
        }

        visited.erase(curr);
        connections[curr] = {};

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.empty()){
            return true;
        }
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            connections[u].push_back(v);
            connections[v].push_back(u);
        }

        if(!dfs(0,-1)) {
            return false;
        }
        std::cout << count;
        return count == n;
        

    }
};
