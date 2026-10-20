class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size()+1,0);

        for (int i = 1; i < prefixSum.size();i++) {
            prefixSum[i] = nums[i-1] + prefixSum[i-1];
        }

        unordered_map<int,int> sumFreq;
        int count = 0;

        for (int n : prefixSum) {
            int target = n-k;
            
            if (sumFreq.count(target)) {
                count+=sumFreq[target];
            }

            sumFreq[n]++;
        }
        
        return count;
    }
};