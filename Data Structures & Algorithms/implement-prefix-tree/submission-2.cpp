class TriNode{
public:

    unordered_map<char,TriNode*> children;

    bool end_of_word;

    TriNode(){
        end_of_word = false;
    }
};

class PrefixTree {
public:
    TriNode* root;

    PrefixTree() {
        root = new TriNode();
    }
    
    void insert(string word) {

        TriNode* curr = root;
        int i = 0;

        while (i < word.size()){
            if (curr->children.contains(word[i])) {
                curr = curr->children[word[i]];
            } else {
                curr->children[word[i]] = new TriNode();
                curr = curr->children[word[i]];
            }
            if (i == (word.size()-1)){
                curr->end_of_word = true;
            }
            i++;
        }
    }
    
    bool search(string word) {
        
        TriNode* curr = root;
        int i = 0;

        while (i < word.size()) {
            if (curr->children.contains(word[i])) {
                curr = curr->children[word[i]];
            } else {
                return false;
            }
            if (i == word.size()-1) {
                return curr->end_of_word;
            }
            i++;
        }

        return true;
        
    }
    
    bool startsWith(string prefix) {

        TriNode* curr = root;
        int i = 0;

        while (i < prefix.size()) {
            if (curr->children.contains(prefix[i])) {
                curr = curr->children[prefix[i]];
            } else {
                return false;
            }
            i++;
        }

        return true;

    }
};
