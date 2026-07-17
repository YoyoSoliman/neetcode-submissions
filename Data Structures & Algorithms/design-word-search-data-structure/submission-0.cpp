class TriNode{
public:
    std::unordered_map<char,TriNode*> children;

    bool end_of_word;

    TriNode() {
        end_of_word = false;
    }
};
class WordDictionary {
    TriNode* root;

public:
    WordDictionary() {
        root = new TriNode();
    }
    
    void addWord(string word) {

        TriNode* curr = root;

        for (const char& c: word) {
            if (!(curr->children.contains(c))){
                curr->children[c] = new TriNode();
            }
            curr = curr->children[c];
        }

        curr->end_of_word = true;
    }
    
    bool searchHelper(string word, TriNode* curr,int i){
        if (word.size() == i) {
                return curr->end_of_word;
        }

        if (word[i] == '.'){
            for (auto const& [key, childNode] : curr->children) {
                if (searchHelper(word, childNode, i+1)){
                    return true;
                }
            }
            return false;

        } else {
           if (!curr->children.contains(word[i])) {
            return false;
           } else{
            return searchHelper(word,curr->children[word[i]],i+1);
           }
        }
    }
    bool search(string word) {
        TriNode* curr = root;

        return searchHelper(word,curr,0);
    }

};
