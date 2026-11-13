class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != val) {
                i++;
                count++;
                continue;
            }
            nums.erase(nums.begin()+i);
        }

        return count;
        
    }
};