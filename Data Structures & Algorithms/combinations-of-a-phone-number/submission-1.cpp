class Solution {
public:
    vector<vector<char>> m= {{},{},{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}
    ,{'m','n','o'},{'p','q','r','s'},{'t','u','v'}, {'w','x','y','z'}};

    vector<string> res;
    void bk(int index, string path ,string digits) {
        if (index >= digits.size()) {
            res.push_back(path);
            return;
        }

        for (char c:m[digits[index] - '0']) {
            path+=c;
            bk(index+1,path,digits);
            path.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        string p = "";
        if (digits.empty()) {
            return res;
        }
        bk(0,p,digits);

        return res;
    }
};
