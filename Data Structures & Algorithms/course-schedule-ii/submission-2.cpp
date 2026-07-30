class Solution {
public:
    vector<int> res; 
    std::unordered_map<int,vector<int>> preMap;
    std::unordered_set<int> visited;
    std::unordered_set<int> added;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        for (const auto& p : prerequisites) {
            preMap[p[0]].push_back(p[1]);

        }

        for (int i = 0; i < numCourses;i++) {
            if (!dfs(i)) {
                return {};
            }
        }

        return res;
    }

    bool dfs(int course) {
        if (visited.contains(course)) {
            return false;
        }

        if (preMap[course].empty()) {
            if (!added.contains(course)) {
                added.insert(course);
                res.push_back(course);
            }
            return true;
        }

        visited.insert(course);

        for (int prereq: preMap.at(course)) {
            if (!dfs(prereq)) {
                return false;
            }
        } 
        visited.erase(course);
        preMap[course] = {};
        if (!added.contains(course)) {
            added.insert(course);
            res.push_back(course);
        }

        return true;


    }
};
