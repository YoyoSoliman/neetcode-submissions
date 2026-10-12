class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int curSum = 0;
        int res = INT_MAX;

        while (r < nums.size()) {
            curSum += nums[r];
            r++;
            
            while (curSum >= target) {
                res = min(res,r-l);
                curSum-=nums[l];
                l++;
            }

        }

        if (res == INT_MAX) {
            return 0;
        }
        return res;
    }
};