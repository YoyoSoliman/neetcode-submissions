class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> presum(nums.size()+1,0);

        for (int i = 1; i < presum.size();i++) {
            presum[i] = presum[i-1] + nums[i-1];
        }

        unordered_map<int,int> sum_count;
        int res = 0;

        for (int n : presum) {
            if (sum_count.count(n-k)) {
                res+=sum_count[n-k];
            }
            
            sum_count[n]++;

        }
        
        //[0,-1,-2, -1]
        // 0->1
        return res;

    }
};