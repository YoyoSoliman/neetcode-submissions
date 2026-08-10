class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int index = -1;

        while (l <= r) {
            int m = l + ((r-l)/2);
            string sortedSide = "";

            if (nums[m] == target) {
                return m;
            }

            //check which side is sorted
            if (nums[l] <= nums[m]) {
                sortedSide = "Left";
            } else {
                sortedSide = "Right";
            }

            if (sortedSide == "Left") {
                if (target >= nums[l] && target < nums[m]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            }

            if (sortedSide == "Right") {
                if (target > nums[m] && target <= nums[r]) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
        }
        
        return index;
    }
};
