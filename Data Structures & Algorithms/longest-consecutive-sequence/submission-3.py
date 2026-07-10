class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        #first thought is to order the array and then find out the longest sequence
        #second though is use a set
        k = set()

        for n in nums:
            k.add(n)
        
        max_seq = 0

        #makes it so it doenst check the same sequence again
        for n in k:
            if n-1 not in k:
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