class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int i,int j, string word1,string word2) {
        if (i >=word1.size() and j >= word2.size()) {
            return 0;
        }

        if (i >= word1.size()) {
            return word2.size()-j;
        }


        if (j >= word2.size()) {
            return word1.size()-i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        //choice 1: charcters are the same move on index
        int choice1 = INT_MAX;
        if (word1[i] == word2[j]) {
            choice1 = dfs(i+1,j+1,word1,word2);
        }

        //choice2: replace a character at this positin
        int choice2 = 1 + dfs(i+1,j+1,word1,word2);

        //choice 3: insert a character
        int choice3 = 1 + dfs(i,j+1,word1,word2);

        //choice 4: delete a charcter
        int choice4 = 1 + dfs(i+1,j,word1,word2);

        dp[i][j] = min({choice1,choice2,choice3,choice4});

        

        return dp[i][j];


    }
    int minDistance(string word1, string word2) {
        dp.assign(word1.size(),vector<int>(word2.size(),-1));
        return dfs(0,0,word1,word2);
    }
};
