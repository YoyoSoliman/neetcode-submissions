class Solution {
public:
    vector<vector<int>> res;
    void backtracking(int index, vector<int>& nums,vector<int> path) {
        if (index >= nums.size()) {
            res.push_back(path);
            return;
        }

        //choice 1 : add number to path and move on to next index
        path.push_back(nums[index]);
        backtracking(index+1,nums,path);
        path.pop_back();

        //choice 2: don't add number and move on to the next index
        backtracking(index+1,nums,path);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> p = {};
        backtracking(0,nums,p);
        return res;
    }
};
