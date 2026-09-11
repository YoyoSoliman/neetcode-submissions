class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const vector<int>* smaller = &nums1;
        const vector<int>* bigger = &nums2;

        if (nums2.size() < nums1.size()) {
            smaller = &nums2;
            bigger = &nums1;
        }

        int m = smaller->size();
        int n = bigger->size();
        int l = 0;
        int r = m;
        int ts = (m + n + 1) / 2;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int p2 = ts - mid;

            int maxLeft1;
            if (mid == 0) {
                maxLeft1 = INT_MIN;
            } else {
                maxLeft1 = (*smaller)[mid - 1];
            }

            int minRight1;
            if (mid == m) {
                minRight1 = INT_MAX;
            } else {
                minRight1 = (*smaller)[mid];
            }

            int maxLeft2;
            if (p2 == 0) {
                maxLeft2 = INT_MIN;
            } else {
                maxLeft2 = (*bigger)[p2 - 1];
            }

            int minRight2;
            if (p2 == n) {
                minRight2 = INT_MAX;
            } else {
                minRight2 = (*bigger)[p2];
            }

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return 0.0;
    }
};