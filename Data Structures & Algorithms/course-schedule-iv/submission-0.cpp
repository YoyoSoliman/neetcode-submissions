class Solution {
public:
    bool is_pre = false;
    unordered_set<int> seen;
    unordered_map<int,vector<int>> adjList;


    void dfs(int curr, int target) {
        if (curr == target) {
            is_pre = true;
            return;
        }

        if (is_pre) {
            return;
        }

        if (seen.count(curr)) {
            return;
        }
        seen.insert(curr);

        for (int nei: adjList[curr]) {
            dfs(nei,target);
        }


    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        for (vector<int> prereq:prerequisites){
            adjList[prereq[0]].push_back(prereq[1]);
        }

        vector<bool> res;

        for (vector<int> q: queries) {
            seen.clear();
            is_pre = false;
            dfs(q[0],q[1]);
            res.push_back(is_pre);
        }
        return res;
    }
};