class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> seenNums(amount + 1);

        queue<int> q;
        q.push(0);
        int c = 0;

        while (!q.empty()) {
            int qLen = q.size();
            for (int i = 0; i < qLen;i++) {
                int curr = q.front();
                q.pop();
                if (curr == amount) {
                    return c;
                }
                for (int n : coins) {
                    long long nextVal = (long long)curr + n;
                    if (nextVal <= amount && seenNums[nextVal] == 0) {
                        q.push(nextVal);
                        seenNums[nextVal] = 1;
                    }
                }
            }
            c++;
        }

        return -1;
    }
};
