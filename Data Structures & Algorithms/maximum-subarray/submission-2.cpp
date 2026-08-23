class Solution {
public:
    int maxSubArray(vector<int>& nums) {

    int l = 0;
    int r = 0;

    int m = INT_MIN;
    int currSum = 0;


    while (r < nums.size()) {
        currSum += nums[r];

        m = max(m,currSum);

        if (currSum < 0) {
            currSum = 0;
            l = r;
            r=l;
        }
        r++;
    }

    return m;
    }
};
