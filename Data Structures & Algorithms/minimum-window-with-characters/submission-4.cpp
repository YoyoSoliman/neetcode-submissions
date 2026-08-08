class Solution {

public:

    bool match(unordered_map<char,int>& s, unordered_map<char,int>& t) {
        for (const auto& [key,value] : t) {
            if (!s.contains(key) || value > s[key]) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char,int> charCountofT;

        for (char c : t) {
            charCountofT[c]++;
        }

        int minLen = INT_MAX;
        int mL = -1;
        int mR = -1;

        int l = 0;
        int r = 0;

        unordered_map<char,int> charCountofS;

        while (r < s.size()) {
            charCountofS[s[r]]++;
            while (match(charCountofS,charCountofT)) {
                int size = (r-l) + 1;
                if (size < minLen) {
                    mL = l;
                    mR = r;
                    minLen = size;
                }
                charCountofS[s[l]]--;
                l++;

            }

            r++;
        }

        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(mL,minLen);
    }
};
