class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        return_list = []
        i=0
        j= len(nums) - 1

        while len(return_list) != len(nums):
            total = 1
            count = 0
            while count != len(nums): 
                
                if i != j:
                    total *= nums[j]
                else:
                    i += 1
                
                if j == 0:
                    j = len(nums)
                
                j-=1

                count = count + 1

            return_list.append(total)

        return return_list