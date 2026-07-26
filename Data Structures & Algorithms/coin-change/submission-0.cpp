class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1,-1);
        std::priority_queue<int> maxHeap;


        dp[0] = 0;

        for (int i = 1; i < dp.size();i++) {

            maxHeap = std::priority_queue<int>();

            for (int j = 0; j < coins.size();j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    maxHeap.push(-1 * dp[i - coins[j]]);
                }
            }

            if (maxHeap.empty()){
                dp[i] = -1;
            } else {
                dp[i] = (-1* maxHeap.top()) + 1;
            }

        }

        return dp[amount];
    }
};
