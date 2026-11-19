//dp approach
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
    
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n;i++) {
            dp[i] = dp[i-1] + 1;

            for (int j = 0; j < i;j++) {
                if (dict.count(s.substr(j,i-j))) {
                    dp[i] = min(dp[j],dp[i]);
                }
            }
        }

        return dp[n];
    }
};