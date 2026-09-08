class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow_pointer_index = 0;
        int fast_pointer_index = 0;

        while (true) {
            fast_pointer_index = nums[fast_pointer_index];
            fast_pointer_index = nums[fast_pointer_index];

            slow_pointer_index = nums[slow_pointer_index];

            if (slow_pointer_index == fast_pointer_index) {
                break;
            }
        }

        slow_pointer_index = 0;

        while (slow_pointer_index != fast_pointer_index) {
            slow_pointer_index = nums[slow_pointer_index];
            fast_pointer_index = nums[fast_pointer_index];
        }

        return fast_pointer_index;
    }
};
