class Solution {
public:
    vector<string> res;

    void backtrack(int total, int closed,int open, string path) {
        if (closed==total and open == total) {
            res.push_back(path);
            return;
        }

        if (closed > total || open > total) {
            return;
        }

        //add open
        path+="(";
        backtrack(total,closed,open + 1, path);
        path.pop_back();

        //add closed only if possible (more open then closed)

        if (open > closed) {
            path+=")";
            backtrack(total,closed + 1,open, path);
            path.pop_back();
        }


    }
    vector<string> generateParenthesis(int n) {
        string p;
        backtrack(n,0,0,p);

        return res;
    }
};
