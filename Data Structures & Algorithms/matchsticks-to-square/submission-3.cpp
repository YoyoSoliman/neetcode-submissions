class Solution {
public:
    bool possible = false;

    vector<int> sums;
    void dfs(int index, int target,vector<int>& matchsticks) {
        if (index >= matchsticks.size()) {
            possible = true;
            return;
        }

        for (int i = 0; i < sums.size();i++) {
            int newValue = sums[i] + matchsticks[index];

            if (newValue > target) {
                continue;
            }
            sums[i] = newValue;
            dfs(index+1,target,matchsticks);
            sums[i] -= matchsticks[index];
        }
    }
    bool makesquare(vector<int>& matchsticks) {
        sums.assign(4,0);

        int total = 0;
        for (int n : matchsticks) {
            total+=n;
        }
        
        if (total % 4 != 0) {
            return false;
        }
        sort(matchsticks.rbegin(), matchsticks.rend());
        int target = total/4;

        dfs(0,target,matchsticks);
        return possible;
    }
};