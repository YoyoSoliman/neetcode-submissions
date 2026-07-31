class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0;
        int currSum = 0;
        int maxSum = nums[0];

        for (int i = 0;i<nums.size();i++) {

            if (prev < 0) {
                currSum = nums[i];

            } else {
                currSum+=nums[i];
            }

            maxSum = max(maxSum,currSum);
            prev = currSum;

        }

        return maxSum;
    }
};
