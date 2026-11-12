class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> t;
        set<vector<int>> deadends_set;
        set<vector<int>> seen;

        for (string code : deadends) {
            vector<int> int_code;
            for (int i = 0; i < code.size();i++) {
                char c = code[i];
                int num = c - '0';
                int_code.push_back(num);
            }
            deadends_set.insert(int_code);
        }

        for (int i = 0; i < target.size();i++) {
            char c = target[i];
            int num = c - '0';
            t.push_back(num);
        }

        vector<int> start = {0,0,0,0};
        int res = -1;

        queue<vector<int>> q;
        q.push(start);
        seen.insert(start);

        if (deadends_set.count(start)) {
            return -1;
        }

        if (start == t) {
            return 0;
        }

        int rotations = 0;
        while (!q.empty()) {
            int qlen = q.size();
            for (int i = 0; i < qlen;i++) {
                vector<int> curr = q.front();
                q.pop();

                for (int i = 0; i < curr.size();i++) {
                    vector<int> n = curr;
                    n[i] = (n[i] + 1) % 10;
                    if (n == t) {
                        return rotations+1;
                    }
                    if (!deadends_set.count(n) and !seen.count(n)) {
                        seen.insert(n);
                        q.push(n);

                    }
                    n[i] = (n[i] - 2 + 10) % 10;
                    if (n == t) {
                        return rotations+1;
                    }
                    if (!deadends_set.count(n) and !seen.count(n)) {
                        seen.insert(n);
                        q.push(n);
                    }
                }
            }

            rotations++;
        }

        return -1;
        

    }
};