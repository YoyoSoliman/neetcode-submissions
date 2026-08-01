/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        vector<vector<int>> times;

        for (Interval t:intervals) {
            int x = t.start;
            int y = t.end;
            times.push_back({x,y});
        }
        std::sort(times.begin(),times.end());

        for (int i = 1; i < times.size();i++) {
            if (times[i-1][1] > times[i][0]) {
                return false;
            }

        }
        return true;
    }
};
