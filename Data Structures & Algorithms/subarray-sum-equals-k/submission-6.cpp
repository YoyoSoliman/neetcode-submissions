class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cur_sum = 0;
        unordered_map<int,int> sum_count;
        sum_count[cur_sum]++;
        int res = 0;

        for (int n : nums) {
            cur_sum +=n;
            if (sum_count.count(cur_sum-k)) {
                res+=sum_count[cur_sum-k];
            }

            sum_count[cur_sum]++;
        }

        return res;
    }
};