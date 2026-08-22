class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j,const string& word1,const string& word2) {

        if (i >= word1.size() && j >= word2.size()) {
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


        int c1 = INT_MAX;
        int c2 = INT_MAX;
        int c3 = INT_MAX;
        int c4 = INT_MAX;

        if (word1[i] == word2[j]) {
            c1 = dfs(i+1,j+1,word1,word2);
        } else {
            c2 = 1 + dfs(i+1,j,word1,word2);
            c3 = 1 + dfs(i+1,j+1,word1,word2);
            c4 = 1 + dfs(i,j+1,word1,word2);
        }

        dp[i][j] = min({c1,c2,c3,c4});

        return dp[i][j];

    }
    int minDistance(string word1, string word2) {
        dp.assign(word1.size(),vector<int>(word2.size(),-1));

        return dfs(0,0,word1,word2);
    }
};
