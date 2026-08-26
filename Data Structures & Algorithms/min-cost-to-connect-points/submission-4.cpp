class Solution {
public:

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    unordered_set<int> visited;

    void getConnectedPoints(int node,vector<vector<int>>& points) {
        for (int i = 0; i < points.size();i++) {
            if (i!= node && !visited.count(i)) {
                int mD = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                minHeap.push({mD,i});
            }
        }

    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        visited.insert(0);
        getConnectedPoints(0,points);

        int sum = 0;
        int edges = 0;

        while (edges != points.size()-1 && !minHeap.empty()) {
            int cost = minHeap.top().first;
            int node = minHeap.top().second; 
            minHeap.pop();

            if (!visited.count(node)) {
                visited.insert(node);
                getConnectedPoints(node,points);
                edges++;
                sum += cost;
            }
        }

        return sum;
    }
};
