class Solution {
public:
    vector<int> res;
    int carry = 0;
    void add(int index,vector<int>& digits) {
        if (index < 0) {
            return;
        }
        int number = digits[index];
        if (index == digits.size()-1) {
            number+=1;
        }

        number+=carry;

        if (number < 10) {
            res.push_back(number);
            carry = 0;
        } else {
            string numStr = to_string(number);
            if (index == 0) {
                res.push_back(numStr[1] - '0');
                res.push_back(numStr[0] - '0');
                return;
            }
            carry = numStr[0] - '0';
            res.push_back(numStr[1] - '0');
        }
        add(index-1,digits);
    }
    vector<int> plusOne(vector<int>& digits) {
        add(digits.size()-1,digits);

        int l = 0;
        int r = res.size()-1;

        while (l < r) {
            int tmp = res[l];
            res[l] = res[r];
            res[r] = tmp;

            l++;
            r--;

        }

        return res;
    }
};
