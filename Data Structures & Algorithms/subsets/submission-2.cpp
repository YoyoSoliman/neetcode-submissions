class Solution {
public:
    vector<vector<int>> res;

    void bk (int i,vector<int> path,vector<int>& nums) {
        if (i >= nums.size()) {
            res.push_back(path);
            return;
        }

        //choice 1:add the index
        path.push_back(nums[i]);
        bk(i+1,path,nums);
        path.pop_back();

        //choice 2
        bk(i+1,path,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> p = {};
        bk(0,p,nums);
        return res;
    }
};
