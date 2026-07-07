class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] output = {0,0};

        for (int k = 0; k < nums.length ; k++ ) {
            for(int i = 0; i < nums.length; i++) {
                if ((target - nums[k]) == nums[i] && k != i) {
                    output[0] = i;
                    output[1] = k;
                }
            }
        }
        return output;
    }
}
