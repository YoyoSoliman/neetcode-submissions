class Solution {
public:
    double binaryPow(double x, long long n) {
        if (n == 0) return 1.0;

        double val = binaryPow(x, n / 2);

        if (n % 2 == 0) {
            return val * val;
        } else {
            return val * val * x;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        return binaryPow(x, N);
    }
};