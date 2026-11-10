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
        vector<vector<int>> meeting_intervals;
        for (Interval i: intervals) {
            vector<int> meeting_interval = {i.start,i.end};
            meeting_intervals.push_back(meeting_interval);
        }

        sort(meeting_intervals.begin(),meeting_intervals.end());

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        int max_rooms = 0;

        for (vector<int>& m:meeting_intervals) {
            if (minHeap.empty()) {
                minHeap.push(m[1]);
                max_rooms = max(max_rooms,1);
                continue;
            }

            while (!minHeap.empty() and m[0] >=  minHeap.top()){
                minHeap.pop();
            }

            minHeap.push(m[1]);
            int heap_size = minHeap.size();
            max_rooms = std::max(max_rooms, heap_size);

        }

        return max_rooms;
    }
};
