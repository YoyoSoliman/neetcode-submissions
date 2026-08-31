class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string str:strs) {
            res+= "#";
            res+= to_string(str.size());
            res+="#";
            res+=str;
        }
        return res;
    }
        /* #5#hello#5#world  */
    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;

        while (i < s.size()) {
            if (s[i] == '#') {
                int start_of_number = i + 1;
                int length = 0;
                while (start_of_number + length< s.size() && s[length + start_of_number] != '#'){
                    length++;
                }

                int number = stoi(s.substr(start_of_number,length));

                res.push_back(s.substr(start_of_number + length + 1,number));
                i=start_of_number + length + 1 + number;
            } else {
                i++;
            }
        }

        return res;
    }
};
