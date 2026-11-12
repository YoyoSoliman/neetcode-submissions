class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> num_freq;

        for (int n : nums) {
            num_freq[n]++;
        }

        vector<int> res;
        for (const auto& [key,value] : num_freq) {
            if (value > (nums.size()/3)) {
                res.push_back(key);
            }
        }

        return res;
    }
};