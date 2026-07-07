#include <unordered_map>
#include <string>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> iterations;

        for (const auto& val: nums) {
            if (iterations.contains(val)) {
                return true;
            } else {
                iterations[val] = 1;
            }
        }
        return false;
    }
};