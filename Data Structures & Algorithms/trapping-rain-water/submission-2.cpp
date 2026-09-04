class Solution {
public:
    int trap(vector<int>& height) {

        int right_max = 0;
        int left_max = 0;
        int l = 0;
        int r = height.size()-1;
        int total_water = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                left_max = max(left_max,height[l]);
                if (left_max - height[l] > 0){ 
                    total_water+=left_max - height[l];
                } 
                l++;
            } else {
                right_max = max(right_max,height[r]);
                if (right_max - height[r] > 0) {
                    total_water+=right_max-height[r];
                }
                r--;
            }
        }

        return total_water;
    }
};
