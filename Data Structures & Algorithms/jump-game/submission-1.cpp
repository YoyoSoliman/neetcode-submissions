class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<int> dp(nums.size(),0);
        dp[0] = 1;

        for (int i = 0; i < nums.size();i++){
            if (dp[i] == 1) {
                for (int k = 1; k<nums[i]+1;k++) {
                    if (i+k < nums.size()) {
                        dp[i+k] = 1;
                    }
                }
            }
        } 

        if (dp[nums.size()-1] == 1) {
            return true;
        }    
        return false;
    }
};
