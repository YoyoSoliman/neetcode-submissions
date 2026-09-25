class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        int maxSub = 1;
        int minSub = 1;

        for (int n : nums) {
            if (n < 0) {
                swap(maxSub,minSub);
            }

            maxSub = max(n,maxSub * n);
            minSub = min(n,minSub * n);

            res = max(res,maxSub);

            if (n == 0) {
                maxSub = 1;
                minSub = 1;
            }
        }

        return res;
    }
};
