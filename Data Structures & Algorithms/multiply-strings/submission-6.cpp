class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            result += to_string(sum % 10);
            carry = sum / 10;
        }

        int l = 0, r = result.size() - 1;
        while (l < r) {
            swap(result[l++], result[r--]);
        }

        return result;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<string> additions;

        for (int i = num1.size() - 1; i >= 0; i--) {
            string add = "";
            int carry = 0; 

            for (int z = 0; z < (int)num1.size() - 1 - i; z++) {
                add += "0";
            }

            int bottomNum = num1[i] - '0';

            for (int j = num2.size() - 1; j >= 0; j--) {
                int topNum = num2[j] - '0';
                int number = (bottomNum * topNum) + carry;

                add += to_string(number % 10); 
                carry = number / 10;          
            }

            
            if (carry > 0) {
                add += to_string(carry);
            }

            int l = 0;
            int r = add.size() - 1;
            while (l < r) {
                char tmp = add[l];
                add[l] = add[r];
                add[r] = tmp;
                l++;
                r--;
            }
           
            additions.push_back(add);
        }

        string totalSum = "0";
        for (string s : additions) {
            totalSum = addStrings(totalSum, s);
        }

        return totalSum;
    }
};