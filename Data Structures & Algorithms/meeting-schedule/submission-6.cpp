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
        if (intervals.size() == 0) {
            return true;
        }
        vector<vector<int>> times;

        for (Interval i : intervals) {
            times.push_back({i.start,i.end});
        }

        sort(times.begin(),times.end());

        for (int i = 0; i < times.size()-1;i++) {
            if (times[i][1] > times[i+1][0]) {
                return false;
            }
        }

        return true;
    }
};
