class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // (index of open,index of closed)
        stack<int> st;
        unordered_set<int> badClosed;

        for (int i = 0 ; i < s.size();i++) {
            if (s[i] == ')') {
                if (st.empty()) {
                    badClosed.insert(i);
                } else {
                    st.pop();
                }
            }

            if (s[i] == '(') {
                st.push(i);
            }
        }

        string res = "";
        for (int i = s.size()-1;i >= 0 ; i--) {
            if (s[i] == ')') {
                if (badClosed.count(i)) {
                    continue;
                }
            }

            if (s[i] == '(') {
                if (!st.empty() and st.top() == i) {
                    st.pop();
                    continue;
                }
            }
            res+=s[i];
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
