class Solution {
public:

    std::set<std::pair<int,int>> reg;

    void dfs(int y, int x, vector<vector<char>>& board){
        if (y < 0 || x < 0 || y >= board.size() || x >= board[0].size() || board[y][x] == '#'||board[y][x] == 'X'){
            return;
        }
    
        reg.insert({y,x});
        board[y][x] = '#';


        dfs(y+1,x,board);
        dfs(y-1,x,board);
        dfs(y,x+1,board);
        dfs(y,x-1,board);

    }
    void solve(vector<vector<char>>& board) {

        //for loop to get the connected parts;

        for (int y = 0; y < board.size();y++) {
            for (int x = 0; x<board[0].size();x++){
                if (board[y][x] == 'O') {
                    reg.clear();
                    //find the (y,x) with the region
                    dfs(y,x,board);
                }

                bool touchesBorder = false;

                for (const auto& [ry, rx] : reg) {
                    if (ry == 0 || ry == board.size() - 1 || rx == 0 || rx == board[0].size() - 1) {
                        touchesBorder = true;
                        break; 
                    }
                }
                
                char t = 'X';
                if (touchesBorder) {
                    t = 'O';
                }

                for (const auto& p : reg) {
                    int k = p.first;
                    int j = p.second;

                    board[k][j] = t;
                }
            }
        }

    }
};
