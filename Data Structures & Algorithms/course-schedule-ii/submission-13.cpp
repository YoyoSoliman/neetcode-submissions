class Solution {
public:

    vector<int> states;
    vector<int> res;
    unordered_map<int,vector<int>> adjList;
    bool loop = false;

    void dfs(int n){
        if (states[n] == 2 || loop) {
            return;
        }

        if (states[n] == 1) {
            loop = true;
            return;
        }
        states[n] = 1;

        for (int c : adjList[n]) {
            dfs(c);
        }

        res.push_back(n);
        states[n] = 2;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        states.assign(numCourses,0);

        for (vector<int> prereq: prerequisites) {
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

/*
0->1
*/
