class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int n = s.size();
        std::vector<int> dp(n + 1, 0);

        // Base cases
        dp[0] = 1; // Empty string base case
        dp[1] = 1; // First character (already checked that s[0] != '0')

        for (int i = 2; i <= n; i++) {

            int singleDigit = s[i - 1] - '0';
            if (singleDigit >= 1 && singleDigit <= 9) {
                dp[i] += dp[i - 1];
            }

            int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};