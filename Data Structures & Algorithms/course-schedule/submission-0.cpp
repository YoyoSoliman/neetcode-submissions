#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::unordered_map<int, std::vector<int>> prereqsMap;
    std::unordered_set<int> visited;
    std::unordered_set<int> canComplete;
    bool cycle = false;

    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {

        for (int i = 0; i < prerequisites.size(); i++) {
            prereqsMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; i++) {
       
            if (canComplete.contains(i)) continue;

            dfs(i);

            if (cycle) return false; 
    }
        return true;
    }

    void dfs(int c) {
        if (visited.contains(c)) {
            cycle = true; 
            return;
        }

        visited.insert(c); 

        if (!prereqsMap[c].empty()) {
   
            auto& prereqs = prereqsMap[c];
            for (auto it = prereqs.begin(); it != prereqs.end(); ) {
                if (canComplete.contains(*it)) {
                    it = prereqs.erase(it); 
                } else {
                    ++it;
                }
            }
        }

        if (prereqsMap[c].empty()) {
            canComplete.insert(c);
            visited.erase(c);
            return; 
        } else {
            for (int course : prereqsMap[c]) {
                dfs(course);
            }
        }

        visited.erase(c);
    }
};