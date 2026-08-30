class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> v;
        for (string str : strs) {
            string sorted_str = str;
            std::sort(sorted_str.begin(),sorted_str.end());
            v[sorted_str].push_back(str);
        }

        vector<vector<string>> res;
        for (const auto& [key,value]: v) {
            res.push_back(value);
        }

        return res;
    }
};
