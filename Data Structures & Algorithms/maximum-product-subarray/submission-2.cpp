class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];

        int minF = 1;
        int maxF = 1;

        for (int n : nums) {

            if (n < 0) {
                swap(minF,maxF);
            } 

            minF = min(n, minF * n);
            maxF = max(n, maxF * n);

            maxProd = max(maxProd,maxF);


            if (n == 0) {
                minF = 1;
                maxF = 1;

            } 
        }
        return maxProd;
    }
};
