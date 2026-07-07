class Solution {
    public boolean hasDuplicate(int[] nums) {
        if (nums.length > 1) {
        for (int i = 0; i < nums.length; i++) {
            for (int k = 1; k < nums.length; k++){
                if (nums[i] == nums[k] && i != k) {
                    return true;
                }
            }
        }
        }
        return false;
    }
}
