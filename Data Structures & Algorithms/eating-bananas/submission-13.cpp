class Solution {
public:
    bool possibleSpeed(vector<int>& piles, int rate, int h) {
        int totalHours = 0;
        for (int p : piles) {
            totalHours+= (p + rate - 1) / rate;
        }
        if (totalHours > h) {
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;

        for (int p:piles) {
            r = max(r,p);
        }

        while (l < r) {
            int mid = l + ((r-l)/2);

            if (possibleSpeed(piles,mid,h)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return l;

    }
};
