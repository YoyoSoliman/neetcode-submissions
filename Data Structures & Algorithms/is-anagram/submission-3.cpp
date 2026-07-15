#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {

        
        if (s.size() != t.size()){
            return false;
        }

        std::unordered_map<char,int> count_s;
        std::unordered_map<char,int> count_t;

        for (int i = 0; i < s.size(); i++) {
            if (count_s.contains(s[i])) {
                count_s[s[i]]++;
            } else {
                count_s[s[i]] = 1;
            }
        } 

        for (int i = 0; i < t.size(); i++) {
            if (count_t.contains(t[i])) {
                count_t[t[i]]++;
            } else {
                count_t[t[i]] = 1;
            }
        } 

        return count_s == count_t;




    }
};
