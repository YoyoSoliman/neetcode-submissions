class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int number_of_open = 0;
        string res = "";

        for (char c : s) {
            if (c == ')') {
                if (number_of_open == 0) {
                    continue;
                } else {
                    number_of_open--;
                }
            }

            if (c == '(') {
                number_of_open++;
            }
            res+=c;
        }

        string res_final;

        for (int i = res.size()-1;i >= 0; i--) {
            if (res[i] == '(' and number_of_open > 0) {
                number_of_open--;
                continue;
            }

            res_final+=res[i];
        }

        reverse(res_final.begin(),res_final.end());
        return res_final;
    }
};
