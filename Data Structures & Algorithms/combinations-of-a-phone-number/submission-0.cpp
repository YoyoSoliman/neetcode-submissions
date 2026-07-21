class Solution {
public:

    const vector<string> numTochar = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    vector<string> letterCombinations(string digits) {

        bk(0,"",digits);
        return res;
    }
    void bk (int i,string path,string digits) {

        if (digits.size() == 0) {
            return;
        }

        if (i == digits.size()) {
            res.push_back(path);
            return;
        }

        int digit = digits[i] - '0';
        string letters = numTochar[digit];

        for (int k = 0; k < letters.size();k++) {
            bk(i+1,path + letters[k],digits);
        }
    }
};
