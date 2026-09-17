class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int index, vector<int> path, vector<int>& nums) {
        if (index >= nums.size()) {
            res.push_back(path);
            return;
        }

        //choice 1: add index and move on to next number
        path.push_back(nums[index]);
        backtrack(index+1, path, nums);
        path.pop_back();


        //choice 2
        while (index+1 < nums.size() && nums[index+1] == nums[index]) {
            index++;
        }
        backtrack(index+1, path, nums);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<int> p = {};

        backtrack(0,p,nums);

        return res;
    }
};
