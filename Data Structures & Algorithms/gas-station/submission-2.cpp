class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalT = 0;
        int currT = 0;
        int start_index = 0;

        for (int i = 0; i < cost.size();i++) {
            int d = gas[i] - cost[i];

            totalT +=d;
            currT+=d;

            if (currT < 0) {
                start_index = i + 1;
                currT = 0;
            }

        }

        if (totalT < 0) {
            return -1;
        }

        return start_index;
    }
};
