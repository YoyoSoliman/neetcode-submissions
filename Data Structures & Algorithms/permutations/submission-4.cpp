class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int> path ,unordered_set<int> used, vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size();i++) {
            if (!used.count(i)) {
                used.insert(i);
                path.push_back(nums[i]);
                backtrack(path,used,nums);
                used.erase(i);
                path.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> p = {};
        unordered_set<int> used;

        backtrack(p,used,nums);

        return res;
    }
};
