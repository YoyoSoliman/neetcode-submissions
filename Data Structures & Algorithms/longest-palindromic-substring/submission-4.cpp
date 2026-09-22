class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int left = 0;
        for (int i = 0; i < s.size();i++) {
            //for odd length stings
            int l = i;
            int r = i;

            while (l >= 0 && r < s.size()) {
                if (s[l] != s[r]) {
                    break;
                }
                l--;
                r++;
            }
            if (maxLen <= r-l-1) {
                maxLen = r-l-1;
                left = l+1;
            }

            //for even length stings
            l = i;
            r = i+1;

            while (l >= 0 && r < s.size()) {
                if (s[l] != s[r]) {
                    break;
                }
                l--;
                r++;
            }
            if (maxLen < r-l-1) {
                maxLen = r-l-1;
                left = l + 1;
            }
        
        }

        return s.substr(left,maxLen);
    }
};
