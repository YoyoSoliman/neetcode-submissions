#include <unordered_set>
#include <string>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;

        for (int val: nums) {
            if (seen.contains(val)) {
                return true;
            } else {
                seen.insert(val);
            }
        }
        return false;
    }
};