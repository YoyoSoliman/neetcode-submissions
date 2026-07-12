class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        l = 0
        r = 0
        longest = 0
        alph_count = {}
        
        def findMaxAlphCount():
            m = 0
            for val in alph_count.values():
                if val > m:
                    m = val
            return m  
        
        while r < len(s):
            alph_count[s[r]] = alph_count.get(s[r], 0) + 1
            
            curr_window = r - l + 1
            
            if curr_window - findMaxAlphCount() <= k:
                if longest < curr_window:
                    longest = curr_window
                r += 1
            else:
                alph_count[s[r]] -= 1 
                alph_count[s[l]] -= 1
                l += 1 
                
        return longest