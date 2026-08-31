class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> nums;

        for (string token: tokens) {
            if (token == "+") {
                int first_number = nums.top();
                nums.pop();
                int second_number = nums.top();
                nums.pop();
                nums.push(first_number+second_number);
            } else if (token == "-") {
                int first_number = nums.top();
                nums.pop();
                int second_number = nums.top();
                nums.pop();
                nums.push(second_number-first_number);
            } else if (token == "*") {
                int first_number = nums.top();
                nums.pop();
                int second_number = nums.top();
                nums.pop();
                nums.push(first_number*second_number);
            } else if (token == "/") {
                int first_number = nums.top();
                nums.pop();
                int second_number = nums.top();
                nums.pop();
                nums.push(second_number/first_number);
            } else {
                nums.push(stoi(token));
            }
        }

        return nums.top();
    }
};
