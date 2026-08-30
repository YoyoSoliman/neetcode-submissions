class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> c;
        
        for (int i = 0;i < nums.size();i++) {
            int comp = target - nums[i];
            if (c.count(comp)) {
                return {c[comp],i};
            }
            c[nums[i]] = i;
        }

        return {-1};
    }
};
