class Solution {
public:
    vector<vector<string>> res;

    void bk(vector<string> path,int currentRow,set<int> unavailableCols, set<int> unavailableDiagonals,set<int> unavailableAntiDiag,int queensNeeded,int currentQ) {

        if (queensNeeded == currentQ) {
            res.push_back(path);
            return;
        }

        string cR = "";

        for (int i = 0; i<queensNeeded;i++) {
            cR +=".";
        }

        for (int i = 0;i < queensNeeded;i++) {
            if (!unavailableCols.count(i) && !unavailableDiagonals.count(currentRow - i) && !unavailableAntiDiag.count(currentRow + i)) {
                cR[i] = 'Q';
                unavailableCols.insert(i);
                unavailableDiagonals.insert(currentRow - i);
                unavailableAntiDiag.insert(currentRow + i);
                path.push_back(cR);
                bk(path,currentRow + 1, unavailableCols,unavailableDiagonals,unavailableAntiDiag,queensNeeded,currentQ + 1);

                cR[i] = '.';
                unavailableCols.erase(i);
                unavailableAntiDiag.erase(currentRow + i);
                unavailableDiagonals.erase(currentRow - i);
                path.pop_back();
            }
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> p = {};
        set<int> u;
        set<int> z;
        set<int> y;

        bk(p,0,u,z,y,n,0);

        return res;
    }
};
