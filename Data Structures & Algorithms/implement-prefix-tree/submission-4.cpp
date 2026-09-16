class TriNode{
public:
    bool endOfWord;
    unordered_map<char,TriNode*> children;

    TriNode(){
        endOfWord = false;
    }
};
class PrefixTree {

public:
    TriNode* start;

    PrefixTree() {
        start = new TriNode();
    }
    
    void insert(string word) {
        TriNode* curr = start;
        for (char c : word) {
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
    
    bool search(string word) {
        TriNode* curr = start;

        for (char c : word) {
            if (curr->children.count(c)) {
                curr = curr->children[c];
            } else {
                return false;
            }
        }

        return curr->endOfWord;


    }
    
    bool startsWith(string prefix) {
        TriNode* curr = start;

        for (char c : prefix) {
            if (curr->children.count(c)) {
                curr = curr->children[c];
            } else {
                return false;
            }
        }

        return true;
    }
};
