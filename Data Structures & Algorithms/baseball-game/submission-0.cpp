class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for (string& s : operations) {
            int newRec;
            if (s == "+") {
                newRec = record[record.size()-1] + record[record.size()-2];
                record.push_back(newRec);
            } else if (s == "D") {
                newRec = record[record.size()-1] * 2;
                record.push_back(newRec);
            } else if (s == "C") {
                record.pop_back();
            } else {
                record.push_back(std::stoi(s));
            }
            std::cout<< newRec << std::endl;
        }

        int res = 0;

        for (int n : record) {
            res+=n;
        }

        return res;
    }
};