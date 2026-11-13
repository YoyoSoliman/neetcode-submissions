class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> index_to_num;

        for (int i = 0; i < n;i++) {
            index_to_num[(i + k) % n] = nums[i];
        }

        for (const auto&[key,value]: index_to_num) {
            nums[key]=value;
        }

    }
};