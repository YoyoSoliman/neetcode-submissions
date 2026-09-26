class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adjList;
        wordList.push_back(beginWord);

        for (int i = 0; i < wordList.size();i++) {
            for (int j = i + 1; j < wordList.size();j++) {
                int differences = 0;
                for (int z = 0; z < beginWord.size();z++) {
                    if (wordList[i][z] != wordList[j][z]) {
                        differences++;
                    }
                }
                if (differences <= 1) {
                    adjList[wordList[i]].push_back(wordList[j]);
                    adjList[wordList[j]].push_back(wordList[i]);
                }
                
            }
        }

        int changes = 1;

        queue<string> q;
        unordered_set<string> seen;

        q.push(beginWord);
        seen.insert(beginWord);

        while (!q.empty()) {
            int qLen = q.size();

            for (int i = 0; i < qLen;i++) {
                string w = q.front();
                q.pop();

                if (w == endWord) {
                    return changes;
                }

                for (string word: adjList[w]) {
                    if (!seen.count(word)) {
                        q.push(word);
                        seen.insert(word);
                    }
                    
                }

            }
            changes++;
        }
        

        return 0;

    }
};
