class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int index, int currSum,int target, vector<int> path,vector<int>& candidates){

        if (currSum == target) {
            res.push_back(path);
            return;
        }

        if (currSum > target || index >= candidates.size()) {
            return;
        }

        //choice 1 : add number and move on to next value
        path.push_back(candidates[index]);
        backtrack(index+1,currSum + candidates[index], target,path,candidates);
        path.pop_back();

        //choice 2: don't add umber and mobve to next Uniue number;
        while (index + 1 < candidates.size() && candidates[index] == candidates[index+1]) {
            index++;
        }

        backtrack(index+1,currSum, target,path,candidates);


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(),candidates.end());
        vector<int> p = {};
        backtrack(0,0,target,p,candidates);

        return res;


    }
};
