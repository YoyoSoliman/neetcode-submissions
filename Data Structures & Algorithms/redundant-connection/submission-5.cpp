class Solution {
public:
    vector<int> parent;
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    bool un(int i,int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI==rootJ) {
            return false;
        }
        parent[rootI] = rootJ;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.assign(edges.size()+1,0);

        for (int i = 1;i < parent.size();i++) {
            parent[i] = i;
        }
        
        for (vector<int> edge: edges){
            if (!un(edge[0],edge[1])) {
                return edge;
            }
        }

        return {};
    }   
};
