class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> numbers_in_window;
        int array_size = nums.size();
        for (int i = 0; i < min(k+1,array_size);i++) {
            if (numbers_in_window.count(nums[i])) {
                return true;
            }
            numbers_in_window.insert(nums[i]);
        } 

        int r = k+1;
        int l = 0;

        while (r < nums.size()) {
            numbers_in_window.erase(nums[l]);
            if (numbers_in_window.count(nums[r])) {
                return true;
            }
            numbers_in_window.insert(nums[r]);
            r++;
            l++;
        }

        return false;
    }
};