class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        int resL=-1;
        int resR = -1;
        int curLen = 0;

        for (int i = 0; i < s.size();i++) {
            int l = i;
            int r = i;
            int curLen = 0;
            //the odd case
            while (l >=0 && r < s.size()) {
                
                if (s[l] == s[r]) {
                    curLen = r-l + 1;
                    if (curLen > len) {
                        resL=l;
                        resR=r;
                        len = curLen;
                    }
                    l--;
                    r++;
                } else {
                    break;
                }
            }

            l = i;
            r = i+1;
            curLen = 0;

            while (l >=0 && r < s.size()) {
                
                if (s[l] == s[r]) {
                    curLen = r-l + 1;

                    if (curLen > len) {
                        resL=l;
                        resR=r;
                        len=curLen;
                    }
                    l--;
                    r++;
                } else {
                    break;
                }
            }
        }

        return s.substr(resL,len);
    }
};
