class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,0);
        dp[s.size()] = 1;

        for (int i = dp.size()-2;i >= 0; i--) {
            for (string word : wordDict) {
                if (i + word.size() <= s.size() && s.substr(i,word.size()) == word && dp[i] == 0) {
                    dp[i] = dp[i + word.size()];
                }
            }
        }

        return dp[0];
    }
};
