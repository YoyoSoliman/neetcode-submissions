class Solution {
public:
    set<int> seen;
    unordered_map<int,vector<int>> adj;

    void dfs(int node, int father) {
        seen.insert(node);

        for (int children : adj[node]) {
            if (children != father) {
                if (!seen.count(children)) {
                    dfs(children,node);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        for (int i = 0; i < edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int count = 0;


        for (int i = 0;i < n;i++) {
            if (!seen.count(i)) {
                count++;
                dfs(i,-1);
            }
        }

        return count;


    }   
};
