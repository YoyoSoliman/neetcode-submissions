#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> minStops(n, INT_MAX);
        unordered_map<int, vector<vector<int>>> adjList;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        for (int i = 0; i < flights.size(); i++) {
            adjList[flights[i][0]].push_back({flights[i][2], flights[i][1]});
        }

        minHeap.push({0, src, 0});

        while (!minHeap.empty()) {
            vector<int> top = minHeap.top();
            minHeap.pop();

            int price = top[0];
            int node = top[1];
            int stops = top[2];

            if (node == dst) {
                return price;
            }

            if (stops >= minStops[node] || stops > k) {
                continue;
            }
            minStops[node] = stops;

            for (vector<int> nei : adjList[node]) {
                int neiPrice = nei[0];
                int neiNode = nei[1];
                
                minHeap.push({price + neiPrice, neiNode, stops + 1});
            }
        }

        return -1;
    }
};