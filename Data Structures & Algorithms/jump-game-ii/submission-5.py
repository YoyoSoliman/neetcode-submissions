class Solution:
    def jump(self, nums: List[int]) -> int:
        l = 0
        r = 0
        jumps = 0

        while r <len(nums) - 1:
            maxDist = 0
            for i in range(l,r+1):
                maxDist = max(maxDist,i + nums[i])
            
            l = r+1
            r = maxDist
            jumps+=1
        
        return jumps