class Solution {
public:

    vector<int> parents;

    int find(int node) {
        if (parents[node] == node) {
            return node;
        }

        int root = find(parents[node]);
        parents[node] = root;

        return root;
    }

    bool merge(int node1,int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2) {
            return false;
        }

        parents[root1] = root2;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parents.assign(edges.size() + 1,0);
        for (int i = 1; i < parents.size();i++) {
            parents[i] = i;
        }

        for (vector<int> edge: edges) {
            int n1 = edge[0];
            int n2 = edge[1];

            if (!merge(n1,n2)) {
                return edge;
            }

        }

        return{-1,-1};

    }
};
