class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> char_index;
        for (int i = 0; i < order.size();i++) {
            char_index[order[i]] = i;
        }

        for (int i = 0; i < words.size()-1;i++) {
            string w1 = words[i];
            string w2 = words[i+1];

            for (int j = 0; j < w1.size();j++) {
                if (w2.size() <= j) {
                    return false;
                }

                if (char_index[w1[j]] < char_index[w2[j]]) {
                    break;
                } else if (char_index[w1[j]] > char_index[w2[j]]) {
                    return false;
                } else {
                    continue;
                }
            }
        }

        return true;
    }
};