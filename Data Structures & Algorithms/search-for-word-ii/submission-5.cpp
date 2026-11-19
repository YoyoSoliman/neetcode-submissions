class TriNode{
public:
    std::unordered_map<char,TriNode*> children;

    bool endOfWord;

    TriNode() {
        endOfWord = false;
    }
};

class Solution {
public:
    TriNode* start = new TriNode();
    vector<string> res;
    void addWord(string word) {
        TriNode* curr = start;
        for (char c: word) {
            if (curr->children.count(c)) {
                curr = curr->children[c];
            } else {
                TriNode* n = new TriNode();
                curr->children[c] = n;
                curr = curr->children[c];
            }
        }

        curr->endOfWord = true;
    }

    void backtracking(vector<vector<char>>& board,int r, int c, string path,TriNode* curr) {
        if (curr->endOfWord) {
            res.push_back(path);
            curr->endOfWord = false;
        }
            
        if (r < 0 || c < 0 || r >=board.size() || c >= board[0].size() || board[r][c] == '#') {
            return;
        }

        if (curr->children.count(board[r][c])) {
            char tmp = board[r][c];
            
            path += board[r][c];
            board[r][c] = '#';

            backtracking(board,r+1,c,path,curr->children[tmp]);
            backtracking(board,r-1,c,path,curr->children[tmp]);
            backtracking(board,r,c-1,path,curr->children[tmp]);
            backtracking(board,r,c+1,path,curr->children[tmp]);

            path.pop_back();
            board[r][c] = tmp;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string word : words) {
            addWord(word);
        }
        for (int i = 0; i < board.size();i++) {
            for (int j = 0; j < board[0].size();j++) {
                backtracking(board,i,j,"",start);
            }
        }

        return res;
    }
};
