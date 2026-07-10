class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded_str = ''

        for s in strs:
            encoded_str += str(len(s)) + "#" + s

        return encoded_str

    def decode(self, s: str) -> List[str]:
        
        l = []
        while len(s) != 0:
            i=0
            while s[i] != "#":
                i+=1

            n = int(s[0:i])

            l.append(s[i+1:i+1+n])

            s = s[i+1+n:len(s)]


            
            
        return l