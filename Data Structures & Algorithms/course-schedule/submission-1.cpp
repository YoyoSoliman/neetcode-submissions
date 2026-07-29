#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::unordered_map<int, std::vector<int>> preMap;
    std::unordered_set<int> visited;

    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        
        for (const auto& req : prerequisites) {
            preMap[req[0]].push_back(req[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int course) {
        if (visited.contains(course)) {
            return false;
        }

        if (preMap[course].empty()) {
            return true;
        }

        visited.insert(course); 

        for (int pre : preMap[course]) {
            if (!dfs(pre)) {
                return false;
            }
        }

        visited.erase(course); 
        preMap[course] = {};    
        
        return true;
    }
};