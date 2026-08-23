class Solution {
public:
    vector<vector<int>> res;
    void bk(int i,vector<int>& candidates, int target,vector<int>& path,int currSum) {

        if (currSum == target) {
            res.push_back(path);
            return;
        }

        if (i >= candidates.size() || currSum > target) {
            return;
        }   


        //choice 1, take it and move on to next elemnt
        path.push_back(candidates[i]);
        bk(i + 1, candidates,target,path,currSum + candidates[i]);
        path.pop_back();

        //choice 2, dont take it and move on to next unique number
        while (i+1< candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }

        bk(i + 1, candidates,target,path,currSum);


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(),candidates.end());
        vector<int> p = {};
        bk(0,candidates,target,p,0);

        return res;
    }
};
