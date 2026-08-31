class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,double>> timeToDestination(speed.size());

        for (int i = 0;i < speed.size();i++) {
            double t = target;
            timeToDestination[i] = {position[i],(t - position[i])/speed[i]};
        }

        std::sort(timeToDestination.rbegin(),timeToDestination.rend());

        std::stack<double> s;
        s.push(timeToDestination[0].second);
        for (int i = 1; i < timeToDestination.size();i++) {
            if (s.top() < timeToDestination[i].second) {
                s.push(timeToDestination[i].second);
            }
        }

        return s.size();
    }
};
