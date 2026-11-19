class TriNode{
public:
    std::unordered_map<char,TriNode*> children;

    bool endOfWord;

    TriNode() {
        endOfWord = false;
    }
};

class WordDictionary {
public:

    TriNode* start;

    WordDictionary() {
        start = new TriNode();
    }
    
    void addWord(string word) {
        TriNode* curr = start;
        for (char c: word) {
            if (curr->children.count(c)) {
                curr = curr->children[c];
            } else {
                TriNode* n = new TriNode();
                curr->children[c] = n;
                curr = curr->children[c];
            }
        }

        curr->endOfWord = true;
    }

    bool dfs(TriNode* curr,const string& word, int index) {
        if (index >= word.size()) {
            return curr->endOfWord;
        }

        if (word[index] == '.') {
            bool possible = false;
            for (const auto&[key,value]: curr->children) {
                possible = dfs(value,word,index+1);
                if (possible) {
                    return true;
                }
            }
        }

        if (curr->children.count(word[index])) {
            return dfs(curr->children[word[index]], word, index+1);
        } else {
            return false;
        }
    }
    bool search(string word) {
        return dfs(start,word,0);
    }
};
