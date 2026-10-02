class Solution {
public:
    vector<int> parents;
    int find(int i) {

        if (parents[i] == i) {
            return i;
        }

        int p = find(parents[i]);
        parents[i] = p;

        return p;

    }

    bool un(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI == rootJ) {
            return false;
        }

        parents[rootI] = rootJ;

        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        parents.assign(points.size(),0);

        for (int i = 0; i < parents.size();i++) {
            parents[i] = i;
        }
        
        priority_queue<vector<int>,
               vector<vector<int>>,
               greater<vector<int>>> minHeap;

        for (int i = 0; i < points.size();i++) {
            for (int j = i +1;j < points.size();j++) {
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];

                int d = abs(xi-xj) + abs(yi-yj);

                minHeap.push({d,i,j});
            }
        }

        int numOfEdges = 0;
        int total = 0;

        while (numOfEdges < points.size()-1) {
            while(!un(minHeap.top()[1],minHeap.top()[2])) {
                minHeap.pop();
            }

            total += minHeap.top()[0];
            numOfEdges++;
            minHeap.pop();
        }

        return total;

    }
};