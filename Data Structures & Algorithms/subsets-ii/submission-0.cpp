class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void bk(vector<int>& nums,vector<int>& path, int index) {
        //base case
        if (index >= nums.size()) {
            res.push_back(path);
            return;
        }

        //option 1: add nums[i] then move on
        path.push_back(nums[index]);
        bk(nums,path,index+1);
        path.pop_back();

        //option 2: skip nums[i] and all identical numbers to it
        while (index+1 < nums.size() && nums[index] == nums[index+1]) {
            index++;
        }
        bk(nums,path,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        bk(nums,path,0);

        return res;
        
    }
};
