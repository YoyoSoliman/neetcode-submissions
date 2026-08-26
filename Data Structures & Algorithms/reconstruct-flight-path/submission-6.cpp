class Solution {
public:
    vector<string> res;
    unordered_map<string,vector<string>> adjList; 

    void dfs(string node) {
        while(!adjList[node].empty()) {
            string nextN = adjList[node].back();
            adjList[node].pop_back();

            dfs(nextN);
        }

        res.push_back(node);

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::sort(tickets.begin(),tickets.end());
        for (vector<string> ticket:tickets) {
            adjList[ticket[0]].push_back(ticket[1]);
        }

        for (auto& [airport, destinations] : adjList) {
            sort(destinations.rbegin(), destinations.rend());
        }

        dfs("JFK");

        std::reverse(res.begin(),res.end());
        return res;

    }
};
