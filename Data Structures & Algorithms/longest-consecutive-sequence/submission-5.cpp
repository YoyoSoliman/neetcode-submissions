class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> numbers;

        for (int n:nums) {
            numbers.insert(n);
        }

        int res = 0;

        for (int n:nums) {
            if (!numbers.count(n-1)) {
                int count = 0;
                int number = n;
                while (numbers.count(n)) {
                    count++;
                    n++;
                }
                res = max(count,res);
            }
        }

        return res;
    }
};
