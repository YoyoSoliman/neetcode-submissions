class Solution {
public:
    vector<vector<int>> res;
    void bk(vector<int>& nums, vector<int>& path) {
        if (nums.size() == 0) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size();i++) {

            int tmp = nums[i];

            path.push_back(tmp);

            nums.erase(nums.begin()+i);

            bk(nums,path);

            path.pop_back();
            nums.insert(nums.begin() + i, tmp);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> p = {};
        bk(nums,p);

        return res;
    }
};
