class Solution {
public:
    bool isPali(string s, int start, int end) {
        if (start == end){
            return true;
        }

        while (start < end) {
            if (s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxLen = 0;
        string maxStr = "";
        int r = 0;
        int l = 0;

        for (int i = 0; i < s.size();i++) {
            r = s.size()-1;
            l = i;

            while (!isPali(s,l,r)) {
                r--;
            }

            int curLen = (r-l) + 1;

            if (curLen > maxLen) {
                maxLen = curLen;
                maxStr = s.substr(l,curLen);
            }
        }

        return maxStr;
    }
};
