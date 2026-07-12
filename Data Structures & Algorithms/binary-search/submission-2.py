class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        l=0
        mid = int(len(nums)/2)
        h = len(nums) - 1

        while l <= h:
            if nums[mid] < target:
                l=mid+1
                mid = int(l + (h- l)/2)
            elif nums[mid] > target:
                h=mid-1
                mid = int((l+h)/2)
            else:
                return mid

        return -1
