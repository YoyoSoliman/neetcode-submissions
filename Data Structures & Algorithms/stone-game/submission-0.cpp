class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j, vector<int>& piles) {
        if (j < i) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        //choice 1 alice takes from left and bob takes from left
        int choice1 = dfs(i+2,j,piles) + piles[i];

        //choice 2 alice takes from left and bob takes from right
        int choice2 = dfs(i+1,j-1,piles) + piles[i];

        //choice 3 alice takes from ight and bob takes from left
        int choice3 = dfs(i+1,j-1,piles) + piles[j];

        //choice 4
        int choice4 = dfs(i,j-2,piles) + piles[j];

        dp[i][j] = max({choice1,choice2,choice3,choice4});
        return dp[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        dp.assign(piles.size(),vector<int>(piles.size(),-1));
        int totalSum = 0;
        for (int n : piles) {
            totalSum+=n;
        }
        int score = dfs(0,piles.size()-1,piles);

        if (score > totalSum-score) {
            return true;
        }

        return false;
    }
};