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

        if (intervals.empty()){
            return 0;
        }
        vector<vector<int>> times;

        for (Interval interval : intervals) {
            int x = interval.start;
            int y = interval.end;

            times.push_back({x,y});
        }

        std::sort(times.begin(),times.end());
        
        int rooms = 1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        minHeap.push(times[0][1]);

        for (int i = 1; i < intervals.size();i++) {
            if (minHeap.top() > times[i][0]) {
                rooms+=1;
                minHeap.push(times[i][1]);
            } else {
                    minHeap.pop();
                    minHeap.push(times[i][1]);
                }
            
        }

        return rooms;
    }
};
