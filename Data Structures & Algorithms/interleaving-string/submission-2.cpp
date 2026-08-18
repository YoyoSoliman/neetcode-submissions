class Solution {
public:
    string p1, p2, p3;
    vector<vector<int>> memo;

    bool dfs(int i, int j) {
        if (i == p1.size() && j == p2.size()) {
            return true;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (i < p1.size() && p1[i] == p3[i + j] && dfs(i + 1, j)) {
            return memo[i][j] = 1;
        }
        if (j < p2.size() && p2[j] == p3[i + j] && dfs(i, j + 1)) {
            return memo[i][j] = 1;
        }

        return memo[i][j] = 0;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        
        p1 = s1; p2 = s2; p3 = s3;
        memo.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return dfs(0, 0);
    }
};