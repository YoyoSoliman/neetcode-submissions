class Solution {
public:
    int rob1(vector<int>& nums,int start,int end){
        int point1 = 0;
        int point2 = 0;

        for (int i = start; i < end;i++) {
            int tmp = max(nums[i] + point1,point2);
            point1=point2;
            point2 = tmp;
        }
        return point2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0]; // Base case: 1 house

        return max(rob1(nums, 0, n - 1), rob1(nums, 1, n));
        
    }
};
