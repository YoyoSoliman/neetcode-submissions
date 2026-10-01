class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        int wordSize = beginWord.size();

        queue<string> q;
        unordered_set<string> seenWords;

        q.push(beginWord);
        seenWords.insert(beginWord);

        int changes = 0;

        while (!q.empty()) {
            int qLen = q.size();
            changes++;

            for (int i = 0; i < qLen;i++) {
                string curr = q.front();
                q.pop();
                if (curr == endWord) {
                    return changes;
                }
                for (int i = 0; i < curr.size();i++) {
                    char ori = curr[i];

                    for (char c = 'a'; c <= 'z';c++) {
                        curr[i] = c;
                        if (!seenWords.count(curr) && wordSet.count(curr)) {
                            q.push(curr);
                            seenWords.insert(curr);
                        }

                        curr[i] = ori;
                    }
                }
            }
        }

        return 0;
    }
};
