class Solution {
public:
    int tribonacci(int n) {
        if (n==0) {
            return 0;
        }

        if (n==1) {
            return 1;
        }
        if (n==2) {
            return 1;
        }
        vector<int> seq(n+1,0);

        seq[1] = 1;
        seq[2] = 1;

        for (int i = 3; i < seq.size();i++) {
            seq[i] = seq[i-3] + seq[i-2] + seq[i-1];
        }

        return seq[n];
    }
};