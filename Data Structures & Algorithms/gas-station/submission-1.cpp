class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0;
        int sumCost = 0;
        vector<int> diff(cost.size(),0);

        for (int i = 0; i < gas.size();i++) {
            sumGas += gas[i];
            sumCost += cost[i];
            diff[i] = gas[i] - cost[i];
        }  

        if (sumCost > sumGas) {
            return -1;
        }

        int total = 0;
        int index = 0;

        for (int i = 0; i < diff.size();i++) {

            total += diff[i];
            if (total < 0) {
                total = 0;
                index = i+1;
            }

        }

        return index;
    }
};
