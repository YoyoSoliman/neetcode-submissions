class Solution {
public:
    bool possibleSpeed(vector<int>& piles,int bph,int target) {
        int total = 0;
        for (int n : piles) {
            total += (n + (long long)bph - 1) / bph;
        }

        if (total <= target) {
            return true;
        } else {
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = 0;

        for (int n : piles) {
            r = max(n,r);
        }

        int l = 1;

        while (l < r) {
            int mid = l + ((r-l)/2);
            if (possibleSpeed(piles,mid,h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
        
    }
};
