class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1Map;
        unordered_map<char,int> s2Map;

        for (char c : s1) {
            s1Map[c]++;
        }

        for (int i = 0; i < s1.size();i++) {
            s2Map[s2[i]]++;
        }

        int l = 0;
        int r = s1.size();

        while (r < s2.size()) {
            if (s1Map == s2Map) {
                return true;
            }
            s2Map[s2[l]]--;
            if (s2Map[s2[l]] == 0) {
                s2Map.erase(s2[l]);
            }
            s2Map[s2[r]]++;
            l++;
            r++;
        }

        return s1Map == s2Map;
    }
};
