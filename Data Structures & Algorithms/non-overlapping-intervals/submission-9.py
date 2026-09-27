class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()

        count = 0
        curr = intervals[0]
        for i in range(1,len(intervals)):
            if curr[1] > intervals[i][0]:
                curr[0] = max(curr[0],intervals[i][0])
                curr[1] = min(curr[1],intervals[i][1])
                count+=1
            else:
                curr = intervals[i]

        return count