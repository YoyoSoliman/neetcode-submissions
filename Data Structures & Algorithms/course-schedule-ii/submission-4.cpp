class Solution {
public:
    vector<int> states;
    vector<int> res;
    bool loop = false;
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

        for (int n : adjList[curr]) {
            dfs(n);
        }

        res.push_back(curr);
        states[curr] = 2;


    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        states.assign(numCourses,0);

        for (vector<int> prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0 ; i < numCourses;i++) {
            dfs(i);
        }

        if (loop) {
            return {};
        }

        return res;
    }
};
