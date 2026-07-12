class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1):
            return False

        s1_map = {}
        s2_map = {}
        k=len(s1)
        l=0
        r=l+k

        for s in s1:
            if s not in s1_map:
                s1_map[s] = 1
            else:
                s1_map[s]+=1

        for i in range(l,r):
            if s2[i] not in s2_map:
                s2_map[s2[i]] = 1
            else:
                s2_map[s2[i]] +=1

        if s1_map == s2_map:
                return True

        while r < len(s2):
            if s1_map == s2_map:
                return True
            else:
                s2_map[s2[l]] -= 1
                if s2_map[s2[l]] == 0:
                    s2_map.pop(s2[l])
                l+=1
                
                r+=1

                if s2[r-1] not in s2_map:
                    s2_map[s2[r-1]] =1
                else:
                    s2_map[s2[r-1]] +=1

            if s1_map == s2_map:
                return True

        return False         