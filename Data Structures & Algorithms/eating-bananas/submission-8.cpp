class Solution {
public:
    bool possibleEatingRate(int eatRate, vector<int>& piles, int h) {
        int total = 0;

        for (int p : piles) {
            total += (p + eatRate - 1)/eatRate;
        }

        if (total <= h) {
            return true;
        }

        return false;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1;

        for (int p : piles) {
            r = max(r,p);
        }

        while (l < r) {
            int mid = ((r-l)/2) + l;
            if (possibleEatingRate(mid,piles,h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
