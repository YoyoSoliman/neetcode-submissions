class Solution {
public:
    vector<vector<string>> res;
    vector<string> part;

    bool isPali(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(int i, const string& s) {
        if (i >= s.size()) {
            res.push_back(part);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (isPali(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));
                backtrack(j + 1, s);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(0, s);
        return res;
    }
};