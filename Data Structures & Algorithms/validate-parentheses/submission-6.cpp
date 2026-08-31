class Solution {
public:
    bool isValid(string s) {
        std::stack<char> t;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                t.push(s[i]);
            }

            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (t.empty()) {
                    return false;
                }
                if (t.top() == '(' && s[i] == ')') {
                    t.pop();
                    continue;
                }
                if (t.top() == '{' && s[i] == '}') {
                    t.pop();
                    continue;
                }
                if (t.top() == '[' && s[i] == ']') {
                    t.pop();
                    continue;
                }

                return false;
            }

        }
        if (!t.empty()) {
            return false;
        }
        return true;
    }
};
