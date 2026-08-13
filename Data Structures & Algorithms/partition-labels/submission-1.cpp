class Solution {
public:
    map<char,int> current;
    map<char,int> charToIndex;

    vector<int> partitionLabels(string s) {

        for (int i = 0;i<s.size();i++) {
            charToIndex[s[i]] = i;
        }

        int l = 0; 
        int r = 0;
        
        vector<int> res;
        int curJump = -1;

        while (r < s.size()) {
            
            curJump = max(curJump, charToIndex[s[r]]);

            if (r == curJump) {
                res.push_back((r-l) + 1);
                curJump = -1;
                l = r +1;
                r=r+1;
            } else {
                r++;
            }

        }

        return res;
    }
};
