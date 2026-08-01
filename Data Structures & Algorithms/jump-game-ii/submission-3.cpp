class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int l = 0;
        int r = 0;

        while (r < nums.size()-1) {
            int farthest = 0;
            for (int i = l; i < r+1;i++){
                farthest = max(farthest, i+nums[i]);
            }
            l = r+1;
            r=farthest;
            jumps+=1;

        }

        return jumps;
    }
};
