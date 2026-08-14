class Solution {
public:
    bool makeEqual(vector<string>& words) {

        int n = words.size();
        unordered_map<char,int> charApp;

        for (int i = 0;i<n;i++) {
            for (char c: words[i]) {
                charApp[c]++;
            }
        }

        for (const auto& [key, value] : charApp) {
            if (value % n != 0) {
                return false;
            }
        }
        return true;

    }
};