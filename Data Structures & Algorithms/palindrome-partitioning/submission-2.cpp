class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string word) {
        int l = 0;
        int r = word.size()-1;

        while (l < r) {
            if (word[l] != word[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
    void backtracking(int start,int end, vector<string> path,string s) {
        if (start >= s.size()) {
            res.push_back(path);
            return;
        }

        if (end >=s.size()) {
            return;
        }

        //choice 1:
        backtracking(start,end+1,path,s);

        //choice 2: 
        if (isPalindrome(s.substr(start,end-start + 1))) {
            path.push_back(s.substr(start,end-start + 1));
            backtracking(end + 1,end+1,path,s);
        }



        
    }
    vector<vector<string>> partition(string s) {
        vector<string> p;
        backtracking(0,0,p,s);

        return res;
    }
};
