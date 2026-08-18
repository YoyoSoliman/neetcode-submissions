class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> numbers;
        int m = INT_MIN;

        for (int num:nums) {
            numbers.insert(num);
            m = max(m,num);
        }

        for (int i = 0; i <= m;i++) {
            if (!numbers.count(i)) {
                return i;
            }
        }

        return m+1;
    }
};
