class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        unordered_map<char,int> char_freq;

        int f = 0;
        int k = 0;

        for (char c: tasks) {
            char_freq[c]++;
            if (char_freq[c] > f) {
                f = char_freq[c];
                k = 1;
                continue;
            }

            if (char_freq[c] == f) {
                k++;
            }
        }

        int res = (f-1)*(n+1) + k;


        return max(size,res);
    }
};
