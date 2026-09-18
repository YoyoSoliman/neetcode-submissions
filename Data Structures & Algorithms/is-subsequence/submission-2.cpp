class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int index1, int index2, string s, string t) {
        if (index1 >= s.size()) {
            return 1;
        }

        if (index2 >= t.size()) {
            return 0;
        }
        
        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }
        

        int choice1 = 0;
        if (s[index1] == t[index2]) {
            choice1 = dfs(index1+1,index2+1, s,t);
        }

        int choice2 = dfs(index1,index2+1,s,t);

        dp[index1][index2] = choice1 || choice2;

        return dp[index1][index2];



    }
    bool isSubsequence(string s, string t) {
        dp.assign(s.size(), std::vector<int>(t.size(), -1));
        return dfs(0,0,s,t);
    }
};