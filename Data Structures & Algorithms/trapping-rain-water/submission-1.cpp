class Solution {
public:
    int trap(vector<int>& height) {
        
        int total = 0;

        int l = 0;
        int r = height.size()-1;

        int maxL = height[l];
        int maxR = height[r];

        while (l < r) {
            if (maxL <= maxR) {
                l+=1;
                maxL = max(maxL,height[l]);
                total += maxL - height[l];
            } else {
                r--;
                maxR = max(maxR,height[r]);
                total += maxR - height[r];
            }
        } 
    
        return total;
    }
};
