class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& candidates,int index, vector<int>& path, int currSum, int target) {

        if (currSum == target) {
            res.push_back(path);
            return;
        }

        if (index >= candidates.size() || currSum > target) {
            return;
        }

        //option 1: add candidates[index] and move on
        path.push_back(candidates[index]);
        backtrack(candidates,index+1,path,currSum + candidates[index],target);

        //option 2: dont add and move on
        path.pop_back();

        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }

        backtrack(candidates,index+1,path,currSum,target);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        std::sort(candidates.begin(), candidates.end());

        backtrack(candidates,0,path,0,target);
        return res;

    }
};
