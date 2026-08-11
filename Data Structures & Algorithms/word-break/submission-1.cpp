class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1,false);

        dp[s.size()] = true;

        for (int i = s.size()-1; i >= 0;i--) {
            for (string word:wordDict) {
                if (word.size() + i <= s.size()) {
                    string sub = s.substr(i,word.size());
                    if (sub == word && dp[i]==false) {
                        dp[i] = dp[i+word.size()];
                    }
                }
            }
        }

        return dp[0];
    }
};
