class Solution {
public:
    int trap(vector<int>& height) {

        int area = 0;
        vector<int> maxLeft(height.size());

        maxLeft[0] = 0;

        for (int i = 1;i < maxLeft.size();i++) {
            maxLeft[i] = max(maxLeft[i-1],height[i-1]);
        }

        vector<int> maxRight(height.size());
        maxRight[height.size()-1] = 0;

        for (int i = maxRight.size()-2;i >= 0;i--) {
            maxRight[i] = max(maxRight[i+1],height[i+1]);
        }

        for (int i = 0;i < height.size();i++) {
            int v = min(maxLeft[i],maxRight[i]) - height[i];

            if (v > 0) {
                area+=v;
            }
        }

        return area;

    }
};
