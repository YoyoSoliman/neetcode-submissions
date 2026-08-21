#include <vector>
#include <string>

using namespace std;

class Solution {
public:    
    vector<int> dp;

    int dfs(int i, const string& s) {
        // Base case: Reached the end of the string successfully
        if (i == s.size()) {
            return 1;
        }

        // '0' cannot map to any character by itself
        if (s[i] == '0') {
            return 0;
        }

        // Return memoized result if available
        if (dp[i] != -1) {
            return dp[i];
        }

        // Choice 1: Decode 1 digit (s[i])
        int totalWays = dfs(i + 1, s);

        // Choice 2: Decode 2 digits (s[i] and s[i+1]) if within range 10-26
        if (i + 1 < s.size()) {
            if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
                totalWays += dfs(i + 2, s);
            }
        }

        return dp[i] = totalWays;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        dp.assign(s.size(), -1);
        return dfs(0, s);
    }
};