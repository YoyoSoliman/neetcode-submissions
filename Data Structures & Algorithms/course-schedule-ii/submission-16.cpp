class Solution {
public:
    //0->1->2
    unordered_map<int,vector<int>> adjList;
    vector<int> states;
    bool loop = false;
    vector<int> res;

    void dfs(int curr) {
        if (loop) {
            return;
        }

        if (states[curr] == 2){
            return;
        }

        if (states[curr] == 1) {
            loop = true;
            return;
        }

        states[curr] = 1;

        for (int nei: adjList[curr]) {
            dfs(nei);
        }

        res.push_back(curr);
        states[curr] = 2;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        states.assign(numCourses,0);
        for (vector<int> prereqs: prerequisites) {
            adjList[prereqs[0]].push_back(prereqs[1]);
        }

        for (int i = 0; i < numCourses;i++) {
            dfs(i);
            if (loop) {
                return {};
            }
        }

        return res;


    }
};
