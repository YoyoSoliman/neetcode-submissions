class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDist = 0;

        for (int i = 0; i < nums.size();i++) {
            if (maxDist < i) {
                break;
            }

            maxDist = max(maxDist, i + nums[i]);

            if (maxDist >= nums.size()-1) {
                return true;
            }
        }

        return false;
    }
};
