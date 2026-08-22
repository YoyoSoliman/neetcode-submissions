class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j,vector<vector<int>>& matrix) {
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        //choice 1: go up if possible: 
        int choice1 = 0;
        if (i-1 >=0) {

            if (matrix[i-1][j] > matrix[i][j]) {
                choice1 = dfs(i-1,j,matrix);
            }

        }


        //choice 2: go down if possible: 
        int choice2 = 0;
        if (i+1 < matrix.size()) {
            if (matrix[i+1][j] > matrix[i][j]) {
                choice2 = dfs(i+1,j,matrix);
            } 
        }


        //choice 3: go right if possible: 
        int choice3 = 0;
        if (j+1 < matrix[0].size()) {
            if (matrix[i][j+1] > matrix[i][j]) {
                choice3 = dfs(i,j+1,matrix);
            }
        }


        //choice 4: go left if possible: 
        int choice4 = 0;
        if (j-1 >= 0) {

            if (matrix[i][j-1] > matrix[i][j]) {
                choice4 = dfs(i,j-1,matrix);
            }

        }

        dp[i][j] = 1 + max({choice1,choice2,choice3,choice4});

        return dp[i][j];

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        dp.assign(rows,vector<int>(cols,-1));
        int res = 0;

        for (int i = 0; i < rows;i++) {
            for (int j = 0;j<cols;j++) {
                res = max(res,dfs(i,j,matrix));
            }
        }
        return res;
    }
};
