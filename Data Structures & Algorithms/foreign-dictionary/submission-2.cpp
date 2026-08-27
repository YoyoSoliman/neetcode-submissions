class Solution {
public:
    unordered_map<char, bool> visited; // Permanently fully processed nodes
    unordered_map<char, bool> path;    // Nodes currently in the active DFS path
    unordered_map<char, unordered_set<char>> adjList;
    string res = "";

    bool dfs(char c) {
        if (path[c]) return true;      // Cycle found (back-edge in active path)
        if (visited[c]) return false;  // Already fully processed in a previous DFS run

        path[c] = true;

        for (const auto& nei : adjList[c]) {
            if (dfs(nei)) return true;
        }

        path[c] = false;           
        visited[c] = true;             

        res += c;
        return false;
    }

    string foreignDictionary(vector<string>& words) {

        for (const string& word : words) {
            for (char c : word) {
                adjList[c] = unordered_set<char>();
            }
        }

        for (int i = 1; i < words.size(); i++) {
            string word1 = words[i - 1];
            string word2 = words[i];

            int minLen = min(word1.size(), word2.size());

            if (word1.size() > word2.size() && word1.substr(0, minLen) == word2.substr(0, minLen)) {
                return "";
            }

            for (int j = 0; j < minLen; j++) {
                if (word1[j] != word2[j]) {
                    adjList[word1[j]].insert(word2[j]);
                    break;
                }
            }
        }

        for (const auto& [key, value] : adjList) {
            if (dfs(key)) {
                return "";
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};