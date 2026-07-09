class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s = {}
        for i in range(len(nums)):
            s[nums[i]] = i

        print(s)
        l = []

        for i in range(len(nums)):
            if target - nums[i] in s and s[target - nums[i]] != i:
                l.append(i)
                l.append(s[target-nums[i]])
                return l



        