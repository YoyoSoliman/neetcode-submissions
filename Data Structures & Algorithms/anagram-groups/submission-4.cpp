class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (string s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }

            string k;
            for (int freq : count) {
                k += to_string(freq);
                k += '#';
            }

            m[k].push_back(s);
        }
        
        vector<vector<string>> res;
        for (const auto&[key,value]:m) {
            res.push_back(value);
        }

        return res;
    }
};
