class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& nums,int index, vector<int>& path) {

        if (index >= nums.size()) {
            res.push_back(path);
            return;
        }

        //include nums[i]
        path.push_back(nums[index]);
        backtracking(nums,index+1,path);
        path.pop_back();

        //don't include 1
        backtracking(nums,index+1,path);

         
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0,path);
        return res;
    }
};
