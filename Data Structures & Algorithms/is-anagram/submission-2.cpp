#include <unordered_map>
#include <string>
class Solution {
public:
    bool isAnagram(string s, string t) {

        
        if (s.size() != t.size()){
            return false;
        }

        std::unordered_map<char,int> count_s;
        std::unordered_map<char,int> count_t;
        int len = s.size();

        for (int i = 0; i < len; i++){
            if (count_s.contains(s[i])) {
                count_s[s[i]]++;
            } else {
                count_s[s[i]] = 1;
            }

            if (count_t.contains(t[i])) {
                count_t[t[i]]++;
            } else {
                count_t[t[i]] = 1;
            }
        }

        if (count_s==count_t) {
            return true;
        }

        return false;


    }
};
