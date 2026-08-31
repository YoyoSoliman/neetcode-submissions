class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct(nums.size());
        prefixProduct[0] = 1;
        

        for (int i = 1;i < prefixProduct.size();i++) {
            prefixProduct[i] = nums[i-1] * prefixProduct[i-1];
        }

        vector<int> postfixProduct(nums.size());
        postfixProduct[nums.size()-1] = 1;

        for (int i = postfixProduct.size()-2;i >= 0;i--) {
            postfixProduct[i] = postfixProduct[i+1] * nums[i+1];
        }

        vector<int> res(nums.size());
        for (int i = 0; i < nums.size();i++) {
            res[i] = postfixProduct[i] * prefixProduct[i];
        }
        return res;
    }
};
