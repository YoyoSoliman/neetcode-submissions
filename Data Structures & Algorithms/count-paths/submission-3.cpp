class Solution {

    //[ 6 3 1
    //  3 2 1
    //. 1 1 0 ]
public:
    int uniquePaths(int m, int n) {

        if (m == 1 || n == 1) {
            return 1;
        }
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));

        for (int i = 0;i < m-1;i++) {
            grid[i][n-1] = 1;
        }

        for (int i = 0;i < n-1;i++) {
            grid[m-1][i] = 1;
        }

        for (int i = m-2; i >=0;i--) {
            for (int j = n-2; j >= 0;j--) {
                grid[i][j] = grid[i+1][j] + grid[i][j+1];
            }
        }

        return grid[0][0];

    }
};
