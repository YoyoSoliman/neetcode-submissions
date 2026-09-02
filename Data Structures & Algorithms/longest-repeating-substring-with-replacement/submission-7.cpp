class Solution {
public:
    /*CCCYYCXCCYY*/



    int maxChar(unordered_map<char,int> m) {
        
        int val = 0;
        for (const auto& [key,value]:m) {
            val = std::max(val,value);
        }
        return val;
    }

    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;

        int longest = 0;
        unordered_map<char,int> m;

        while (r < s.size()) {
            m[s[r]]++;
            int size_of_window = r - l + 1;
            if (size_of_window - maxChar(m) <= k) {
                r++;
                longest = max(size_of_window,longest);
            } else {
                while (size_of_window - maxChar(m) > k) {
                    m[s[l]]--;
                    l++;
                    size_of_window = r - l + 1;
                }
                r++;
            }
        }

        return longest;
    }
};
