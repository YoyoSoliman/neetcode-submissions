class Solution:

    def encode(self, strs: List[str]) -> str:

        encoded_string = ''

        for x in strs: 
            encoded_string += "$(" + str(len(x)) + "@" + x

        return encoded_string

    def decode(self, s: str) -> List[str]:
        return_list = []
        
        i = 0
        j=0

        while i < len(s):

            if s[i] == "$" and s[i + 1] == "(":
                j = i + 2

                while s[j] != "@":
                    j += 1
                
                length = int(s[i+2:j])
                return_list.append(s[j+1 : j + 1 + length])
            
            i += 1
        
        return return_list
