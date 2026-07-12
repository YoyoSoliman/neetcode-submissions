class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        l = []
        nums.sort()
        
        for i in range(len(nums)):

            left = i+1
            right = len(nums)-1
            target = -(nums[i])

            while left < right:

                curr_sum = nums[left] + nums[right]

                if curr_sum == target:
                    m=[nums[i],nums[left],nums[right]]
                    m.sort()
                    if m not in l:
                        l.append(m)

                    left+=1
                    right-=1
                    

                if curr_sum < target:
                    left +=1

                if curr_sum > target:
                    right -=1

        return l

        
