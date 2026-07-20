class Solution {
public:
    bool found = false;
    void backtrack (vector<vector<char>>& board, vector<vector<int>>& seen,string path, string word,int r, int c) {

        if (path == word) {
            found = true;
            return;
        }

        if (path.size() >= word.size()) {
            return;
        }

        if (r + 1 < board.size() && seen[r+1][c] == 0) {
            seen[r+1][c] = 1;
            backtrack(board,seen, path + board[r+1][c],word, r+1,c);
            seen[r+1][c] = 0;
        }

        if (r - 1 >= 0 && seen[r-1][c] == 0) {
            seen[r-1][c] = 1;
            backtrack(board,seen, path + board[r-1][c],word, r-1,c);
            seen[r-1][c] = 0;
        }

        if (c - 1 >= 0 && seen[r][c-1] == 0) {
            seen[r][c-1] = 1;
            backtrack(board,seen, path + board[r][c-1],word, r,c-1);
            seen[r][c-1] = 0;
        }


        if (c + 1 < board[0].size() && seen[r][c+1] == 0) {
            seen[r][c+1] = 1;
            backtrack(board,seen, path + board[r][c+1],word, r,c+1);
            seen[r][c+1] = 0;
        }


    }
    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();
    
        // Creates a 2D vector of size rows x cols, filled with 0 (0 menas that position hasnt been seen)
        vector<vector<int>> seen(rows, vector<int>(cols, 0));

        //i is x, and k is y
        for (int i =0; i < board[0].size();i++) {
            for (int k = 0; k < board.size(); k++) {
                if (board[k][i] == word[0]) {
                    //resets the seen 2d and path
                    string path;
                    for (auto& row : seen) {
                        std::fill(row.begin(), row.end(), 0);
                    }
                    seen[k][i] = 1;
                    backtrack(board,seen,path + board[k][i],word,k,i);
                    seen[k][i] = 0;

                }
            }
        }
        
        return found;

    }
};
