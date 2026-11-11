class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<int> q;
        unordered_set<int> seen; 
        seen.insert(0);
        q.push(0);

        int res= 0;
        while (!q.empty()) {
            int qlen = q.size();
            for (int i = 0; i < qlen;i++) {
                int curr_amount = q.front();
                q.pop();

                if (curr_amount == amount) {
                    return res;
                }

                for (int c : coins) {
                    int new_amount = curr_amount + c;
                    if (new_amount > amount || seen.count(new_amount)) {
                        continue;
                    }
                    seen.insert(new_amount);
                    q.push(new_amount);
                }
            }
            res++;
        }

        return -1;
    }
};
