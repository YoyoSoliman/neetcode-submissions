class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currRes = 0;
        int res = 0;

        for (int n : nums) {
            if (n==1) {
                currRes++;
            } else {
                res = max(res,currRes);
                currRes = 0;
            }
        }

        res = max(res,currRes);

        return res;
    }
};