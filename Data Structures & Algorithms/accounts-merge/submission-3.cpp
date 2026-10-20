class Solution {
public:
    unordered_map<string,vector<string>> adjList;
    unordered_set<string> seenEmails;
    vector<string> p;

    void dfs(string curr) {

        if (seenEmails.count(curr)) {
            return;
        }

        seenEmails.insert(curr);
        p.push_back(curr);

        for (string nei: adjList[curr]) {
            dfs(nei);
        }


    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        for (vector<string>& account:accounts) {
            for (int i = 1; i <account.size();i++ ) {
                for (int j =i+1; j < account.size();j++) {
                    adjList[account[i]].push_back(account[j]);
                    adjList[account[j]].push_back(account[i]);
                }
            }
        }

        vector<vector<string>> res;
        for (vector<string> account: accounts) {
            if (seenEmails.count(account[1])) {
                continue;
            }
            p = {};

            dfs(account[1]);
            sort(p.begin(),p.end(),std::greater<std::string>());
            p.push_back(account[0]);

            reverse(p.begin(),p.end());

            res.push_back(p);
        }

        return res;



    }
};