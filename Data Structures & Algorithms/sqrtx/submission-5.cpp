class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;

        int l = 1;
        int r = x;
        int res = 1;

        while (l <= r) {
            long long mid = l + ((r - l) / 2); 

            if (mid * mid <= x) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};