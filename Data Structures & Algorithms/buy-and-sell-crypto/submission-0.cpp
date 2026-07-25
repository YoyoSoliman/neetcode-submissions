class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int l = 0;//when we buy
        int r = 1;//when we sell

        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l=r;
                r = l+1;
            } else{
                int currProf = prices[r] - prices[l];
                maxProf = max(currProf,maxProf);
                r++;
            }

        }

        return maxProf;
    }
};
