class Solution {
public:
    bool found = false;

    void backtracking(vector<vector<char>>& board,string word, int index,int r, int c) {

        if (found) {
            return;
        }

        if (index >= word.size()) {
            found = true;
            return;
        }

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }

        if (board[r][c] == '#') {
            return;
        }



        if (board[r][c] == word[index]) {
            char tmp = board[r][c];
            board[r][c] = '#';

            backtracking(board,word,index+1,r + 1,c);
            backtracking(board,word,index+1,r - 1,c);
            backtracking(board,word,index+1,r,c + 1);
            backtracking(board,word,index+1,r,c - 1);

            board[r][c] = tmp;
        }
        


    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size();i++) {
            for (int j = 0; j < board[0].size();j++) {
                backtracking(board,word,0,i,j);
            }
        }

        return found;
    }
};
