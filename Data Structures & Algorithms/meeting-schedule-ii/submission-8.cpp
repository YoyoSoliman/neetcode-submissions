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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        vector<vector<int>> times;

        for (Interval i : intervals) {
            times.push_back({i.start,i.end});
        }

        sort(times.begin(),times.end());

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        minHeap.push(times[0][1]);
        int minRooms = 1;

        for (int i = 1; i < times.size();i++) {
            while (!minHeap.empty() && times[i][0] >= minHeap.top()) {
                minHeap.pop();
            }
            minHeap.push(times[i][1]);

            minRooms = std::max(minRooms,static_cast<int>(minHeap.size()));
        }

        return minRooms;

    }
};
