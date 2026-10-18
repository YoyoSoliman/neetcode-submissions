class Solution {
public:
    bool helperPal(int l, int r, string s) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        while (l < r) {
            if (s[l] != s[r]) {
                return helperPal(l+1,r,s) || helperPal(l,r-1,s);
            }
            l++;
            r--;
        }

        return true;
    }
};