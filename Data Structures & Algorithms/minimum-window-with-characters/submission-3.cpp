class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) countT[c]++;

        int have = 0, need = countT.size();
        int minLen = INT_MAX;
        int mL = -1;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            // Check if current char meets the required count in T
            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            // Shrink window in O(1) condition check
            while (have == need) {
                int size = r - l + 1;
                if (size < minLen) {
                    minLen = size;
                    mL = l;
                }

                // Remove s[l] from window
                char leftChar = s[l];
                window[leftChar]--;
                
                // If removing s[l] breaks a requirement, decrement 'have'
                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) {
                    have--;
                }
                
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(mL, minLen);
    }
};