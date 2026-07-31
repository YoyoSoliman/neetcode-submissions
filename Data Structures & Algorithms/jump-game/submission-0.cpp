class Solution {
public:
    bool con = false;
    void bk(int index, vector<int>& nums) {
        if (con) {
            return;
        }
        if (index == nums.size()-1) {
            con = true;
            return;
        }

        if (index >= nums.size()) {
            return;
        }

        if (nums[index]==0) {
            return;
        }
        for (int i = 1; i < nums[index]+1;i++){
            bk(index+i,nums);
        }
    }
    bool canJump(vector<int>& nums) {
        bk(0,nums);

        return con;
    }
};
