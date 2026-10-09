class Solution {
public:
    vector<vector<int>> res;

    void bk(int k, int n, int start,vector<int> path) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n;i++) {
            path.push_back(i);
            bk(k,n,i+1,path);
            path.pop_back();
            
        }
    }
    vector<vector<int>> combine(int n, int k) {
        int s = 1;
        vector<int> p;

        bk(k,n,s,p);

        return res;
    }
};