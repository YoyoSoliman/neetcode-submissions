#include <vector>
#include <string>

using namespace std;

class Solution {
public:    
    vector<int> dp;

    int dfs(int i, const string& s) {
        if (i == s.size()) {
            return 1;
        }

        if (s[i] == '0') {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int totalWays = dfs(i + 1, s);

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