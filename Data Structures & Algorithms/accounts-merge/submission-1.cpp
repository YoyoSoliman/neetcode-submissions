#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailToAccount;

        // Step 1: Union accounts that share emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToAccount.count(email)) {
                    dsu.unite(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }

        // Step 2: Group all emails by their DSU root account index
        unordered_map<int, vector<string>> rootToEmails;
        for (auto& [email, accIdx] : emailToAccount) {
            int root = dsu.find(accIdx);
            rootToEmails[root].push_back(email);
        }

        // Step 3: Format the output (sort emails and prepend account name)
        vector<vector<string>> result;
        for (auto& [rootIdx, emails] : rootToEmails) {
            sort(emails.begin(), emails.end()); // Sort emails alphabetically

            vector<string> account = {accounts[rootIdx][0]}; // Start with the name
            account.insert(account.end(), emails.begin(), emails.end());

            result.push_back(account);
        }

        return result;
    }
};