class TriNode {
public:
    bool end_of_word = false;
    unordered_map<char,TriNode*> children;
    TriNode(){}
    
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
            if (!curr->children.count(c)) {
                TriNode* n = new TriNode();
                curr->children[c] = n;
            } 

            curr = curr->children[c];
        }

        curr->end_of_word = true;
    }
    
    bool search(string word) {
        TriNode* curr = start;
        for (char c : word) {
            if (!curr->children.count(c)) {
                return false;
            }
            curr = curr->children[c];
        }

        return curr->end_of_word;
    }
    
    bool startsWith(string prefix) {
        TriNode* curr = start;
        for (char c : prefix) {
            if (!curr->children.count(c)) {
                return false;
            }
            curr = curr->children[c];
        }

        return true;
    }
};
