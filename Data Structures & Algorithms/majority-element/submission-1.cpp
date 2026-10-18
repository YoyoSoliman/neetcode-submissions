class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mapF;
        for (int n : nums) {
            mapF[n]++;
            if (mapF[n] > nums.size()/2) {
                return n;
            }
        }
        return -1;
    }
};