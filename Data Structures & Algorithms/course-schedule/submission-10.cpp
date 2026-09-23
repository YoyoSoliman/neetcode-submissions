class Solution {
public:

    unordered_set<int> seen;
    unordered_set<int> cycleFree;
    bool loop = false;
    unordered_map<int,vector<int>> adjList;

    void dfs(int curr) {
        if (loop) {
            return;
        }

        if (seen.count(curr)) {
            loop = true;
            return;
        }

        seen.insert(curr);

        for (int n : adjList[curr]) {
            if (!cycleFree.count(n)) {
                dfs(n);
            }
        }

        seen.erase(curr);
        cycleFree.insert(curr);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for (vector<int> prereq: prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
        }

        for (int i =0;i<numCourses;i++) {

            if (!cycleFree.count(i)) {
                dfs(i);
            }
            if (loop) {
                return false;
            }
            cycleFree.insert(i);
        }
        
        return true;

    }
};
