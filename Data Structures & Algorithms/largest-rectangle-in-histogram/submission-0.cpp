#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentHeight;
            if (i == n) {
                currentHeight = 0;
            } else {
                currentHeight = heights[i];
            }

            while (!st.empty() && currentHeight < heights[st.top()]) {
                int poppedIndex = st.top();
                st.pop();
                
                int h = heights[poppedIndex];
                int w;

                if (st.empty()) {
                    w = i;
                } else {
                    w = i - st.top() - 1;
                }

                int currentArea = h * w;
                if (currentArea > maxArea) {
                    maxArea = currentArea;
                }
            }

            st.push(i);
        }

        return maxArea;
    }
};