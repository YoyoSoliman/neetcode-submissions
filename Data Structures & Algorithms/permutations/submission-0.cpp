class Solution {

    vector<vector<int>> res;
    vector<int> path;

public:
    void backtracking(vector<int>& nums,vector<int>& path, int index) {
        //base case: if index is out of bounds
        if (nums.size()==0) {
            res.push_back(path);
            return;
        }
        //for each choice their n,n-1,n-2 choices
        for (int i = 0; i < nums.size();i++) {
            path.push_back(nums[i]);
            int tmp = nums[i];
            nums.erase(nums.begin() + i);
            
            backtracking(nums, path, index + 1);

            nums.insert(nums.begin() + i,tmp);
            path.pop_back();
        }
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums,path,0);
        return res;
    }
};
