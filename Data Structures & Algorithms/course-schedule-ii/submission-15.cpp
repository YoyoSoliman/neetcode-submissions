class Solution {
public:
    vector<int> states;
    unordered_map<int,vector<int>> adjList;
    bool loop = false;
    vector<int> res;

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
        return;
    }

    //b -> a
    //[a,b]
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        states.assign(numCourses,0);
        for (vector<int> prereq:prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
        }    

        for (int i = 0; i < numCourses;i++) {
            dfs(i);

            if (loop) {
                return {};
            }
        }

        reverse(res.begin(),res.end());

        return res;




    }
};
