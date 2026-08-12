class Solution {
private:
    vector<int> par;
    vector<int> rank;

    int find(int n) {
        if (n == par[n]) {
            return par[n];
        }
        par[n] = find(par[n]);
        return par[n];
    }

    bool un(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) {
            return false; 
        }

        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] +=rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] +=rank[p1];
        }
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        par.resize(n + 1);
        rank.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }

        for (const auto& edge : edges) {
            if (!un(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};