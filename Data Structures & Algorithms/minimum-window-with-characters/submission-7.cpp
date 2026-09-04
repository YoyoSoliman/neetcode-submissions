#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> tMap(128, 0);
        vector<int> sMap(128, 0);

        int required = 0;
        for (char c : t) {
            if (tMap[c] == 0) required++;
            tMap[c]++;
        }

        int l = 0, r = 0;
        int formed = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        while (r < s.size()) {
            char c = s[r];
            sMap[c]++;

            if (tMap[c] > 0 && sMap[c] == tMap[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }

                char leftChar = s[l];
                if (tMap[leftChar] > 0 && sMap[leftChar] == tMap[leftChar]) {
                    formed--;
                }
                sMap[leftChar]--;
                l++;
            }

            r++;
        }

        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(startIdx, minLen);
    }
};