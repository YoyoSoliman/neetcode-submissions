class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            if (seen.count(n)) {
                return n;
            }
            seen.insert(n);
        }
    }
};
