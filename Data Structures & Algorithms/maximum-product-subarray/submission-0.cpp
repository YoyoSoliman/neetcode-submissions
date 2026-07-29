#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int currMax = 1;
        int currMin = 1;
        
        int res = *std::max_element(nums.begin(), nums.end()); 

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                currMin = 1;
                currMax = 1;
                continue; 
            } 

            int tmp = currMax; 

            currMax = std::max({nums[i] * currMax, nums[i] * currMin, nums[i]});
            currMin = std::min({nums[i] * tmp, nums[i] * currMin, nums[i]});
            
            res = std::max(res, currMax);
        }
    
        return res;
    }
};