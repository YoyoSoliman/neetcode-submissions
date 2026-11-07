class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;
        int row = 0;

        while (l <= r) {
            int mid = l + ((r-l)/2);

            if (matrix[mid][0] <= target and matrix[mid][matrix[0].size()-1] >= target) {
                row = mid;
                break;
            } else if (matrix[mid][0] > target ) {
                r = mid-1;
            } else {
                l = mid+1;
            }

        }


        l = 0;
        r = matrix[row].size() - 1;

        while (l <= r) {
            int mid = l + ((r-l)/2);
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                l = mid + 1;
            } else {
                r = mid-1;
            }
        }

        return false;
    }
};
