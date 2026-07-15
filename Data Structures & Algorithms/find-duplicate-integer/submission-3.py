class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
                
        slowP=0
        fastP=0

        slowP = nums[slowP]
        fastP = nums[nums[fastP]]

        while slowP != fastP:
            slowP = nums[slowP]
            fastP = nums[nums[fastP]]
        
        np = 0

        while np != slowP:
            slowP = nums[slowP]
            np = nums[np]

            if np == slowP:
                return np

