class Solution {
public:
    vector<vector<int>> res;

    void bk(vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);  
            bk(nums, start + 1);          
            swap(nums[start], nums[i]); 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        bk(nums, 0);
        return res;
    }
};