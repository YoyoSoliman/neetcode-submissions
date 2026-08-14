class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<double>> posAndArrivalTime(position.size());

        for (int i = 0;i<posAndArrivalTime.size();i++) {
            double arrivalTime = static_cast<double>(target - position[i]) / speed[i];
            posAndArrivalTime[i] = {static_cast<double>(position[i]),arrivalTime};
        }

        std::sort(posAndArrivalTime.begin(), posAndArrivalTime.end());
        stack<double> s;

        for (int i = posAndArrivalTime.size()-1;i>=0;i--) {
            if (s.empty()) {
                s.push(posAndArrivalTime[i][1]);
                continue;
            }

            if (posAndArrivalTime[i][1] > s.top()) {
                s.push(posAndArrivalTime[i][1]);
            }

        }

        return s.size();
    }
};
