class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLen = -1;
        unordered_map<char,int> m;

        for (int i = 0;i<s.size();i++) {
            if(!m.count(s[i])) {
                m[s[i]] = i;
            } else {
                maxLen = max(maxLen, i - m[s[i]] - 1);
            }
        }

        return maxLen;
    }
};