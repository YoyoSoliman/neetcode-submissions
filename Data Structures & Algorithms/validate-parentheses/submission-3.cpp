class Solution {
public:
    bool isValid(string s) {

        std::stack<char> par;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '[' || s[i] == '{' || s[i] == '(' ) {
                par.push(s[i]);

            } else {
                if (par.size() == 0) {
                    return false;
                }

                char v = par.top();
                par.pop();

                if ((s[i] == ']' && v != '[') || 
                (s[i] == ')' && v != '(') ||
                ((s[i] == '}' && v != '{')))  {
                    return false;
                }
            }
        }

        if (par.size() != 0) {
            return false;
        }

        return true;
    }
};
