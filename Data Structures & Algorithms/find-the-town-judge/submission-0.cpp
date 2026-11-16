class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        unordered_map<int,vector<int>> adjList;
        vector<int> ins(n+1,0);
        for (vector<int> tr : trust) {
            adjList[tr[0]].push_back(tr[1]);
            ins[tr[1]]++;
        }

        int res = -1;

        for (int i = 1;i <=n;i++) {
            if (adjList[i].empty() and ins[i] == n-1) {
                if (res != -1) {
                    return -1;
                } else {
                    res = i;
                }
            }
        }

        return res;
    }
};