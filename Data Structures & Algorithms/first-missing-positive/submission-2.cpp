class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> n;
        for (int num : nums) {
            if (num > 0) {
                n.insert(num);
            }
        }

        for (int i = 1;i <= nums.size()+1;i++) {
            if (!n.count(i)) {
                return i;
            }
        }

        return -1;


    }
};