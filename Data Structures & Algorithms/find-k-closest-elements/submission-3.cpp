class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index;

        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        index = l;

        l = index-1;
        r = index;
        vector<int> res;

        while (res.size() < k) {
            if (l < 0) {
                res.push_back(arr[r]);
                r++;
                continue;
            }

            if (r >= arr.size()) {
                res.push_back(arr[l]);
                l--;
                continue;
            }

            int v1 = abs(arr[l] - x);
            int v2 = abs(arr[r] - x);
            if (v1 <= v2 ) {
                res.push_back(arr[l]);
                l--;
            } else {
                res.push_back(arr[r]);
                r++;
            }
        }

        sort(res.begin(),res.end());
        return res;
    }
};