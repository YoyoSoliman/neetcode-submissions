class Solution {
public:
    bool word_found = false;
    const vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int index,int r,int c, string word, vector<vector<char>>& board) {


        if (index >= word.size() || word_found) {
            word_found = true;
            return;
        }

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }

        if (board[r][c] != word[index]) {
            return;
        }

        char tmp = board[r][c];
        board[r][c] = '#';

        for (const auto& [dr,dc] : dirs) {
            int newR = dr + r;
            int newC = dc + c;

            dfs(index+1,newR,newC,word,board);
        }

        board[r][c] = tmp;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size();r++) {
            for (int c = 0; c < board[0].size();c++) {
                dfs(0,r,c,word,board);
                if (word_found) {
                    return true;
                }
            }
        }

        return false;
    }
};
