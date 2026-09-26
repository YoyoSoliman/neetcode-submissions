class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;

        int currSum = 0;

        for (int n : nums) {
            currSum += n;
            res = max(currSum,res);

            if (currSum < 0) {
                currSum = 0;
            }

        }

        return res;
    }
};
