class Solution {
public:
    vector<int> dp;

    int dfs(int index, string s,vector<string>& wordDict) {
        if (index >= s.size()) {
            return 1;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        for (string word: wordDict) {
            if (s.substr(index,word.size()) == word) {
                if (dfs(index+word.size(),s,wordDict)) {
                    dp[index] = 1;
                    return dp[index];
                }
            }
        }

        dp[index] = 0;
        return dp[index];

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size()+1,-1);
        return dfs(0,s,wordDict);
    }
};
