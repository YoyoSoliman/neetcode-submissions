#include <vector>
class Solution {
public:
int change(int amount, std::vector<int>& coins) {
    int n = coins.size();
    
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));
    
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    
    // Fill the grid
    for (int i = 1; i <= n; ++i) {
        int coin = coins[i - 1];
        for (int a = 1; a <= amount; ++a) {
           
            dp[i][a] = dp[i - 1][a];
            
            
            if (a >= coin) {
                dp[i][a] += dp[i][a - coin];
            }
        }
    }

    return dp[n][amount];
}
        
};
