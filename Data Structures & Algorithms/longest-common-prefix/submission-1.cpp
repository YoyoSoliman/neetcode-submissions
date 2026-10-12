class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int biggestString = INT_MIN;
        int smallestString = INT_MAX;
        for (string str: strs) {
            biggestString = max((int)str.size(),biggestString);
            smallestString = min(smallestString,(int)str.size());
        }

        for (int i = 0; i < smallestString;i++) {
            for (int j = 0; j <strs.size()-1;j++ ) {
                if (strs[j][i] != strs[j+1][i]) {
                    return res;
                }
            }
            res+=strs[0][i];
        }

        return res;
    }
};