class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if not s:
            return 0
            
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
            # 1. Add the incoming character at 'r' to our counts
            alph_count[s[r]] = alph_count.get(s[r], 0) + 1
            
            # 2. Calculate the true window length
            curr_window = r - l + 1
            
            # 3. Check if the window is valid
            if curr_window - findMaxAlphCount() <= k:
                # Valid window! Update our max length and move r forward
                if longest < curr_window:
                    longest = curr_window
                r += 1
            else:
                # Invalid window! 
                # We must undo adding s[r] because r shouldn't move forward yet,
                # and then shrink the window from the left.
                alph_count[s[r]] -= 1 
                alph_count[s[l]] -= 1
                l += 1  # Move l FORWARD to shrink
                
        return longest