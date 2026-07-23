class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //list of all zero
        vector<int> minCost(n);
        minCost[n-1] = cost[n-1];
        minCost[n-2] = cost[n-2];
        for (int i = n-3; i >= 0; i--) {
            minCost[i] = min(minCost[i+1],minCost[i+2]) + cost[i];
        }
        
        return min(minCost[0],minCost[1]);

    }
};
