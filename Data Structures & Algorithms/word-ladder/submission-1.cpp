class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        map<string,vector<string>> adjList;
        set<string> visited;

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        wordSet.insert(beginWord);
        vector<string> allWords(wordSet.begin(), wordSet.end());
        int n = beginWord.size();

        for (size_t i = 0; i < allWords.size(); i++) {
            for (size_t j = i + 1; j < allWords.size(); j++) {
                int diff = 0;
                for (int z = 0; z < n; z++) {
                    if (allWords[i][z] != allWords[j][z]) {
                        if (++diff > 1) break;
                    }
                }
                if (diff == 1) {
                    adjList[allWords[i]].push_back(allWords[j]);
                    adjList[allWords[j]].push_back(allWords[i]);
                }
            }
        }

        queue<string> q;
        q.push(beginWord);
        int count = 0;

        while (!q.empty()) {
            int l = q.size();
            count++;
            for (int i = 0; i < l;i++) {
                string curr = q.front();
                q.pop();
                visited.insert(curr);
                if (curr == endWord) {
                    return count;
                }
                for (string s : adjList[curr]) {
                    if (!visited.count(s)) {
                        q.push(s);
                    }
                }
            }
            
        }

        return 0;
        
    }
};
