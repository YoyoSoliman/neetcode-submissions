#include <algorithm> 
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> r(nums.size());
        if (nums.size()==1) {
            return nums[0];
        }
        r[0] = nums[0];
        r[1] = max(nums[0],nums[1]);

        for (int i = 2; i < nums.size();i++) {
            r[i] = nums[i] + *std::max_element(r.begin(), r.begin()+i-1);
        }

        return max(r[r.size() - 1],r[r.size() - 2]);

    }

};
