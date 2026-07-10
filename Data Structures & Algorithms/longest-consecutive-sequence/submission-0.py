class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        #first thought is to order the array and then find out the longest sequence
        k = set()

        for n in nums:
            k.add(n)
        
        max_seq = 0

        for n in k:
            done = False
            i=1
            while not done:
                if n+i in k:
                    i+=1
                else:
                    done=True
            
            if i > max_seq:
                max_seq=i

        return max_seq