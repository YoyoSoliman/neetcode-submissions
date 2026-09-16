class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int index, int target, vector<int>& path, int currSum, vector<int>& nums) {


        if (currSum > target || index >= nums.size()) {
            return;
        } 

        if (currSum == target) {
            res.push_back(path);
            return;
        }

        //choice 1: add number and stay on the index
        path.push_back(nums[index]);
        backtracking(index,target,path,currSum + nums[index], nums);
        path.pop_back();

        //choice 2: move on to next index
        backtracking(index + 1,target,path,currSum, nums);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> p = {};
        backtracking(0,target,p,0,nums);

        return res;
    }
};
