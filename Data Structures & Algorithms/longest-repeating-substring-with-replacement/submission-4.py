class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        l = 0
        r = 0
        longest = 0
        alph_count = {}
        
        # Helper function fixed: renamed loop variable to 'val' to avoid breaking 'k'
        def findMaxAlphCount():
            m = 0
            for val in alph_count.values():
                if val > m:
                    m = val
            return m  # Returned OUTSIDE the loop
        
        while r < len(s):
            alph_count[s[r]] = alph_count.get(s[r], 0) + 1
            
            curr_window = r - l + 1
            
            # 3. Check if the window is valid
            if curr_window - findMaxAlphCount() <= k:
                if longest < curr_window:
                    longest = curr_window
                r += 1
            else:
                alph_count[s[r]] -= 1 
                alph_count[s[l]] -= 1
                l += 1 
                
        return longest