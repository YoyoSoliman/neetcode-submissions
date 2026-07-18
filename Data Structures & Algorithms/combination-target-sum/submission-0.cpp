class Solution {

    vector<vector<int>> res;
    vector<int> path;


public:
    void backTrack(vector<int>& nums, int index, vector<int>& path,int currSum,int target) {

        //when to add the current path as a valid result
        if (currSum == target) {
            res.push_back(path);
            return;
        }

        //base case(when we know we are done) if current sum exceeds the target or we went trhough all the numbers
        if (index >= nums.size() || currSum > target) {
            return;
        }

        //option 1: stay on current index and add it to path
        path.push_back(nums[index]);
        backTrack(nums,index,path,currSum + nums[index], target);

        //option 3: dont add it and move on
        path.pop_back();
        backTrack(nums,index + 1,path,currSum, target);



    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backTrack(nums,0,path,0,target);
        return res;
    }
};
