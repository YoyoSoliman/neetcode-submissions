class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        l_to_r = [1]
        r_to_l = [1]

        for i in range(1,len(nums)):
            l_to_r.append(l_to_r[i-1] * nums[i-1])
        
        for i in range(len(nums)-1,0,-1):
            r_to_l.insert(0, r_to_l[0] * nums[i])
        
        return [l * r for l, r in zip(l_to_r, r_to_l)]