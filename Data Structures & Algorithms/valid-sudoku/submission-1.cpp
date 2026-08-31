class Solution {
public:
    bool rowsValid(vector<vector<char>>& board) {
        for (int i = 0; i < board.size();i++) {
            unordered_set<char> seen;
            for (int j = 0; j <board[0].size();j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (seen.count(board[i][j])) {
                    return false;
                } else {
                    seen.insert(board[i][j]);
                }
            }
        }

        return true;
    }

    bool colValid(vector<vector<char>>& board) {
        for (int i = 0; i < board[0].size();i++) {
            unordered_set<char> seen;

            for (int j = 0; j < board.size();j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (seen.count(board[j][i])) {
                    return false;
                } else {
                    seen.insert(board[j][i]);
                }
            }
        }
        return true;
    }

    bool boxesValid(vector<vector<char>>& board) {


        for (int i = 0; i < board.size();i+=3) {
            for (int j = 0; j < board[0].size();j+=3) {
                unordered_set<char> seen;
                for (int z = i; z < i + 3;z++) {
                    for (int y = j; y < j + 3;y++) {
                        if (board[z][y] == '.') {
                        continue;
                        }
                        if (seen.count(board[z][y])) {
                            return false;
                        } else {
                            seen.insert(board[z][y]);
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return boxesValid(board) && rowsValid(board) && colValid(board);
    }
};
