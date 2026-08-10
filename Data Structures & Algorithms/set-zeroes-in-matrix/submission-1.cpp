class Solution {
public:

    void setColsRows(vector<vector<int>>& matrix,int x,int y,int rows,int cols) {
        for (int i = 0; i < cols;i++) {
            matrix[y][i] = 0;
        }
        for (int j = 0;j<rows;j++) {
                matrix[j][x] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        std::queue<pair<int,int>> n;

        set<int> rowsToSkip;
        set<int> colsToSkip;

        for (int i = 0; i < rows; i++) {
            for (int j = 0;j < cols;j++) {
                if (matrix[i][j] == 0) {
                    n.push({j,i});
                }
            }
        }

        while (!n.empty()) {
            int x = n.front().first;
            int y = n.front().second;

            setColsRows(matrix,x,y,rows,cols);
            n.pop();
        }
    }
};
