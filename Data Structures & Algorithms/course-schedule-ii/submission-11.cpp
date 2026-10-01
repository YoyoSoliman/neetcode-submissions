class Solution {
public:
    vector<int> res;
    bool loop = false;
    vector<int> states;
    unordered_map<int,vector<int>> adjList;


    void dfs(int curr) {
        if (states[curr] == 2 || loop) {
            return;
        }

        if (states[curr] == 1) {
            loop = true;
            return;
        }
        states[curr] = 1;
        
        for (int nei : adjList[curr]) {
            dfs(nei);
        }
        
        if (loop) {
            return;
        }

        states[curr] = 2;
        res.push_back(curr);


    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        for (vector<int> prereq : prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
        }
        states.assign(numCourses,0);

        for (int i =0; i < numCourses;i++) {
            dfs(i);
            if (loop) {
                return{};
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
