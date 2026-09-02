class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int l = 0;
        int r = 0;
        int longest = 0;

        while (r < s.size()) {
            if (seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            } else {
                seen.insert(s[r]);
                longest = max(longest, r - l + 1);
                r++;
            }
        }

        return longest;
    }
};
