class Solution {
public:
    vector<vector<string>> res;

    void bk(int q,int n,int row, vector<string> path, unordered_set<int>& usedCols,unordered_set<int>& usedDiags,unordered_set<int>& usedAnti) {

        if (q == n) {
            res.push_back(path);
            return ;
        }

        for (int i = 0;i < n;i++) {
            if (!usedCols.count(i) && !usedDiags.count(row-i) && !usedAnti.count(row+i)) {
                usedCols.insert(i);
                usedDiags.insert(row-i);
                usedAnti.insert(row+i);

                std::string str(n,'.');
                str[i] = 'Q';

                path.push_back(str);
                bk(q+1,n,row+1,path,usedCols,usedDiags,usedAnti);
                path.pop_back();

                usedCols.erase(i);
                usedDiags.erase(row-i);
                usedAnti.erase(row+i);

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> p;
        unordered_set<int> q;
        unordered_set<int> r;
        vector<string> path;
        bk(0,n,0,path,p,q,r);
        return res;
    }
};
