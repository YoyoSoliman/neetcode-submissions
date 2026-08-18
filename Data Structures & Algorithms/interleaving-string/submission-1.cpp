class Solution {
public:
    set<vector<int>> badPairs;
    string p1;
    string p2;
    string p3;

    bool dfs(int i,int j) {
        if (i == p1.size() && j == p2.size()) {
            return true;
        }
        if (badPairs.count({i,j})) {
            return false;
        }
        if (i < p1.size() && p1[i] == p3[i+j] && dfs(i+1,j)) {
            return true;
        }
        if (j < p2.size() && p2[j] == p3[i+j] && dfs(i,j+1)) {
            return true;
        }

        badPairs.insert({i,j});
        return false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        p1=s1;
        p2=s2;
        p3=s3;

        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        return dfs(0,0);
    }
};
