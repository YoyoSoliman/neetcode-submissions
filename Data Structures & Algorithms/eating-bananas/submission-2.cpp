class Solution {
public:
    bool isValid(int bph,vector<int>& piles, int goal) {
        long long sum = 0;
        for (int pile : piles) {
            sum += (pile + bph - 1) / bph;
        }

        if (sum <= goal) {
            return true;
        }

        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = -1;

        for (int pile : piles) {
            r = max(r,pile);
        }

        while (l < r) {
            int mid = l + ((r-l)/2);
            if (isValid(mid,piles,h)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return l;
    }
};
