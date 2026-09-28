class Solution {
public:
    /*
    
    */
    vector<vector<int>> dp;
    int dfs(int i, int j,const string& s1, const string& s2,const string& s3) {
        if (i + j >= s3.size()) {
            return 1;
        }

        if (dp[i][j]!=-1) {
            return dp[i][j];
        }

        int choice1 = 0;

        if (i < s1.size() && s1[i] == s3[i+j]) {
            choice1 = dfs(i+1,j,s1,s2,s3);
        }

        int choice2 = 0;

        if (j < s2.size() && s2[j] == s3[i+j]) {
            choice2 = dfs(i,j+1,s1,s2,s3);
        }

        dp[i][j] = choice1 || choice2;

        return dp[i][j];


    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        dp.assign(s1.size() + 1,vector<int>(s2.size() + 1,-1));
        return dfs(0,0,s1,s2,s3);

    }
};
