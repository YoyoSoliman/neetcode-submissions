class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int index, int currSum,int target, vector<int>& stones) {
        if (index >= stones.size()) {
            return currSum;
        }

        if (dp[index][currSum] != -1) {
            return dp[index][currSum];
        }

        //choice 1 dont add stone:
        int choice1 = dfs(index+1,currSum,target,stones);

        //choice 2 add stone:

        int choice2=0;

        if (stones[index] + currSum <= target) {
            choice2 = dfs(index+1, currSum + stones[index],target,stones);
        }

        dp[index][currSum] = max(choice1,choice2);

        return dp[index][currSum];

    }
    int lastStoneWeightII(vector<int>& stones) {

        int total = accumulate(stones.begin(), stones.end(), 0);
        int target = total / 2;

        dp.assign(stones.size(),vector<int>(total+1,-1));


        int best_subset_sum = dfs(0, 0, target, stones);

        return total - (2 * best_subset_sum);
    }
};