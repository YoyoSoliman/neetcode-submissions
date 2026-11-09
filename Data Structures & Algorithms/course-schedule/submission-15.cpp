class Solution {
public:
    unordered_map<int,vector<int>> adjList;
    vector<int> states;
    bool loop = false;

    void dfs(int curr) {
        if (loop == true) {
            return;
        }

        if (states[curr] == 2) {
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
        states[curr] = 2;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        states.assign(numCourses,0);

        for (vector<int> prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0; i < numCourses;i++) {
            dfs(i);
            if (loop) {
                return false;
            }
        }
        return true;
    }
};
