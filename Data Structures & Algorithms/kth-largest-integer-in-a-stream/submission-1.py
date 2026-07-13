import heapq
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.heap = [-x for x in nums]
        heapq.heapify(self.heap)

        self.k = k

    def add(self, val: int) -> int:
        heapq.heappush(self.heap, -1*val)
        l = []
        v = 0
        for i in range(self.k):
            v = heapq.heappop(self.heap)
            l.append(v)
        
        for i in l:
            heapq.heappush(self.heap, i)
        
        return -1 * v

