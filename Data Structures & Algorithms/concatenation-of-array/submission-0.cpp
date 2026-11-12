class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums.size() * 2,0);

        for (int i = 0; i < res.size();i++) {
            res[i] = nums[i%nums.size()];
        }

        return res;
    }
};