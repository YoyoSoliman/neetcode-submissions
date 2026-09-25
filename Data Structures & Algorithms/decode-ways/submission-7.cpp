class Solution {
public:
    vector<int> dp;
    int dfs(int index,string s) {
        if (index >=s.size()) {
            return 1;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        //choice 1: take it as one number:

        int choice1 = 0;
        if (s[index] - '0' != 0) {
            choice1 = dfs(index+1,s);
        }

        int choice2 = 0;
        if (index+1 < s.size() && s[index] - '0' != 0 && stoi(s.substr(index,2)) < 27) {
            choice2 = dfs(index+2,s);
        }   

        dp[index] = choice1 + choice2;

        return dp[index];


    }
    int numDecodings(string s) {
        dp.assign(s.size(),-1);

        return dfs(0,s);
    }   
};
