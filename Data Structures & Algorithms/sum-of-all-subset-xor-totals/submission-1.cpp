class Solution {
public:
    int res = 0;
    void dfs(int index,int x,vector<int>& nums) {
        if (index >= nums.size()) {
            res+=x;
            return;
        }

        //choice 1: 
        dfs(index+1,x ^ nums[index],nums);


        //choice 2: 
        dfs(index+1,x,nums);
    }
    int subsetXORSum(vector<int>& nums) {
        dfs(0,0,nums);

        return res;
    }
};