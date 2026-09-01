class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size();i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = -1 * nums[i];
            int l = i+1;
            int r = nums.size()-1;

            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r+1]) {
                        r--;
                    }
                } else if (nums[l] + nums[r] < target) {
                    l++;
                } else {
                    r--;
                }
            } 
        }

        return res;
    }
};
