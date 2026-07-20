class Solution {
public:
    vector<string> res;
    string path;

    void backtrack(int n, int open, int closed, string path) {

        if (open==n && closed == n) {
            res.push_back(path);
            return;
        }
        if (open > n || closed > n) {
            return;
        }

        if (closed < open) {
            path += ")";
            backtrack(n,open,closed+1,path);
            path.pop_back();
        }

        path += "(";
        backtrack(n,open+1,closed,path);
        path.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        backtrack(n,0,0,path);
        return res;
    }
};
