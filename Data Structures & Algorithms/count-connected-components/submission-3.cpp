class Solution {
public:
    vector<int> parent;
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }

        int p = find(parent[i]);
        parent[i] = p;
        return p;
    }

    bool un(int i,int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI == rootJ) {
            return false;
        }

        parent[rootI] = rootJ;

        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.assign(n,0);

        for (int i = 0; i < n;i++) {
            parent[i] = i;
        }

        int count = n;

        for (vector<int> edge:edges) {
            if (un(edge[0],edge[1])) {
                count--;
            }
        } 
        return count;
    }
};
