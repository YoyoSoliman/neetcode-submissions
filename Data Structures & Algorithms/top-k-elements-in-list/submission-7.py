class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        freq_nums = {}
        for num in nums: 
            if num in freq_nums:
                freq_nums[num] += 1
            else:
                freq_nums[num] = 1
        
        o = 0
        top_k = []

        while o != k:
            m = 0
            n = 0
            for num, freq in freq_nums.items():
                if freq > m:
                    m = freq
                    n = num
            top_k.append(n)
            freq_nums.pop(n)
            o+=1
        
        return top_k

        