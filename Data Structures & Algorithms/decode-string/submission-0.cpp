class Solution {
public:
    string decodeString(string s) {
        stack<int> st1;
        stack<string> st2;

        string res;
        int current_num = 0;
        string curr_string = "";
        for (char c : s) {
            if (isdigit(c)) {
                current_num = current_num * 10 + (c - '0');
                continue;
            }

            if (isalpha(c)) {
                curr_string+=c;
            }

            if (c=='[') {
                st1.push(current_num);
                current_num = 0;
                st2.push(curr_string);
                curr_string = "";
            }

            if (c==']') {
                int count = st1.top();
                st1.pop();

                string prev_string = st2.top();
                st2.pop();

                string repeated = "";
                for (int i = 0; i < count; i++) {
                    repeated += curr_string;
                }

            
                curr_string = prev_string + repeated;
            }
        }

        return curr_string;
    }
};