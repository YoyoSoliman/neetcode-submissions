class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;

        int l = 0;
        int r = 1;

        while (r < prices.size()) {
            int curProf = prices[r] - prices[l];
            maxP = max(maxP,curProf);
            if (prices[r] < prices[l]) {
                l=r;
                r++;
            } else {
                r++;
            }
        }

        return maxP;
    }
};
