class Solution {
public:
    vector<vector<int>> res;

    void bk(int i, int currSum, vector<int>& nums,vector<int>& path,int target) {
        if (currSum == target) {
            res.push_back(path);
            return;
        }

        if (currSum > target || i >= nums.size()) {
            return;
        }

        //choice one: add current number
        path.push_back(nums[i]);
        bk(i,currSum + nums[i], nums,path,target);
        path.pop_back();

        //choice two: move on to next number
        bk(i + 1, currSum, nums, path, target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> p = {};

        bk(0,0,nums,p,target);
        return res;
    }
};
