class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int l = 0;
        int r = 0;
        int res = 0;

        while (r < s.size()) {
            if (!seen.count(s[r])) {
                seen.insert(s[r]);
                r++;
            } else {
                seen.erase(s[l]);
                l++;
            }
            res = max(res, r-l);
        }


        return res;
    }
};
