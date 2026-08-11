class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;
        int num = 0;
        string s = to_string(n);

        while (true) {
            int num = 0;
            for (int i =0;i<s.size();i++) {
                int digit = s[i] - '0';
                num += digit * digit;
            }
            if (num == 1) {
                return true;
            }
            if (seen.count(num)) {
                return false;
            }
            seen.insert(num);
            s = to_string(num);
        }
            
        
    }
};
