class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_set<int> seenNums;

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

                    if (curr+n <= amount && !seenNums.count(curr + n)) {
                        q.push(curr+n);
                        seenNums.insert(curr+n);
                    }
                }
            }
            c++;
        }

        return -1;
    }
};
