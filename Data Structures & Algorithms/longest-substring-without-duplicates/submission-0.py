class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        l=0
        r=0
        seen = set()
        while r < len(s):
            if s[r] in seen:
                seen.remove(s[l])
                l+=1
            else:
                seen.add(s[r])
                r+=1
            curr_window_size = r-l
            if longest < curr_window_size:
                longest = curr_window_size
        
        return longest


        