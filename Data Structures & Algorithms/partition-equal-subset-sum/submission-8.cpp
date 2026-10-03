class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int n : nums) {
            totalSum +=n;
        }

        if (totalSum % 2 == 1) {
            return 0;
        }

        vector<int> dp((totalSum/2) + 1,0);

        dp[0] = 1;

        for (int n : nums) {
            for (int i = totalSum/2;i >= 0;i--) {
                if (i-n >= 0 and dp[i-n] == 1) {
                    dp[i] = 1;
                }
            }
        }

        return dp[totalSum/2];
    }
};
