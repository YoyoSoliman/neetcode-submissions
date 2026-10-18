//recyribve apprach
class Solution {
public:
    vector<int> dp;
    int dfs(int index,string s, vector<string> & dictionary) {
        if (index >= s.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        //choice 1 : treat it like an extra charcter:

        int choice1 = 1 + dfs(index+1,s,dictionary);

        //make a word if we can
        int choice2 = INT_MAX;

        for (string w: dictionary) {
            int wordSize = w.size();

            if (index + wordSize <= s.size() && s.substr(index,wordSize) == w) {
                choice2 = min(choice2, dfs(index + wordSize,s,dictionary));
            }
        }

        dp[index] = min(choice2,choice1);

        return dp[index];
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        dp.assign(s.size(),-1);

        return dfs(0,s,dictionary);
    }
};