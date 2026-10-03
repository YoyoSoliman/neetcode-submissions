class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<int> q;
        q.push(0);

        unordered_set<int> seenNums;
        seenNums.insert(0);

        int c = 0;

        while(!q.empty()) {
            int qLen = q.size();
            for (int i = 0; i < qLen;i++) {
                int n = q.front();
                q.pop();
                if (n== amount) {
                    return c;
                }

                for (int coin : coins) {
                    if (!seenNums.count(coin + n) && coin+n <= amount) {
                        q.push(coin+n);
                        seenNums.insert(coin+n);
                    }
                }
            }
            c++;
        }

        return -1;
    }
};
