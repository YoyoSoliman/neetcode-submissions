class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int,int>> s;
        int maxRect = 0;

        for (int i = 0; i < heights.size();i++) {
            if (s.empty()) {
                s.push({heights[i],i});
                continue;
            }

            int start = i;
            while (!s.empty() && s.top().first > heights[i]) {
                int setH = s.top().first;
                int leftBound = s.top().second;

                int width = i - leftBound;
                int a = width * setH;


                maxRect = max(maxRect, a);
                start = leftBound;
                s.pop();
            }
            s.push({heights[i],start});
        }
        while (!s.empty()){
            int rightBound = heights.size();
            int leftBound = s.top().second;
            int setH = s.top().first;
            int w = rightBound-leftBound;

            maxRect = max(maxRect,setH * w);
            s.pop();
        }
        return maxRect;

    }
};
