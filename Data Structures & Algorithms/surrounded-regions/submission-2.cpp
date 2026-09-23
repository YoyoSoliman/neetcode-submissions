class Solution {
public:
    void dfs(int r,int c, vector<vector<char>>& board) {

        if (r < 0 || c < 0 || r >= board.size() || c >=board[0].size() || board[r][c] == 'X' || board[r][c] == 'L') {
            return;
        }

        board[r][c] = 'L';
        dfs(r+1,c,board);
        dfs(r-1,c,board);
        dfs(r,c-1,board);
        dfs(r,c+1,board);

    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size();i++) {
            dfs(i,0,board);
            dfs(i,board[0].size()-1,board);
        }

        for (int i = 0; i < board[0].size();i++) {
            dfs(0,i,board);
            dfs(board.size()-1,i,board);
        }

        for (int r = 0;r < board.size();r++) {
            for (int c = 0; c < board[0].size();c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                if (board[r][c] == 'L') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
