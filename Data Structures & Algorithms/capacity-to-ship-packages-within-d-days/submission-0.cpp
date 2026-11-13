class Solution {
public:
    bool good_weight(vector<int>& weights,int target_days,int w) {
        int days = 1;
        int curr_w = 0;

        for (int i:weights) {
            if (i > w) {
                return false;
            }

            if (curr_w + i <= w) {
                curr_w+=i;
            } else {
                days++;
                curr_w=i;
            }
        }

        if (days <= target_days) {
            return true;
        } 
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int totalsum = 0;
        for (int w: weights) {
            totalsum+=w;
        }
        int l = 1;
        int r = totalsum;

        while (l < r) {
            int mid = l + ((r-l)/2);
            if (good_weight(weights,days,mid)) {
                r = mid;
            } else {
                l=mid+1;
            }
        }

        return r;
    }
};