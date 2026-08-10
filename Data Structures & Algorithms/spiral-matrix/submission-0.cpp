class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res = {};
        std::unordered_map<string,string> nextDirection;
        nextDirection["Right"] = "Down";
        nextDirection["Down"] = "Left";
        nextDirection["Left"] = "Up";
        nextDirection["Up"] = "Right";
        
        int n = matrix[0].size();
        int m = matrix.size();
        
        int x = 0;
        int y = 0;
        string currD = "Right";
        set<pair<int,int>> seen;
        int i = 0;

        while (i < n*m) {

            res.push_back(matrix[y][x]);
            seen.insert({x,y});
            i++;

            if (currD == "Right") {
                if (x+1 >= n || seen.count({x+1,y})) {
                    currD = nextDirection[currD];
                    y++;
                } else {
                    x++;
                }
            }else if (currD == "Down") {
                if (y+1 >= m || seen.count({x,y+1})) {
                    currD = nextDirection[currD];
                    x--;
                } else {
                    y++;
                }
            } else if (currD == "Left") {
                if (x-1 < 0 || seen.count({x-1,y})) {
                    currD = nextDirection[currD];
                    y--;
                } else {
                    x--;
                }
            } else {
                if (y-1 < 0 || seen.count({x,y-1})) {
                    currD = nextDirection[currD];
                    x++;
                } else {
                    y--;
                }
            }
            

        }

        return res;

    }
};
