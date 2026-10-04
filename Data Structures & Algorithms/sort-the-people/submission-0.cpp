class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> ord;
        for (int i = 0; i <names.size(); i++) {
            ord.push_back({heights[i],names[i]});
        }

        sort(ord.begin(),ord.end());
        vector<string> res;

        for (int i = 0; i < ord.size();i++) {
            res.push_back(ord[i].second);
        }

        reverse(res.begin(),res.end());
        return res;
    }
};