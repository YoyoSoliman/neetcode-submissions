class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        return_list = []
        code_and_words = {}

        for x in strs:
            
            # creates the code for each one
            lst = list(x)
            lst.sort()
            code = ""

            for i in lst:
                code = code + i
            
            if code in code_and_words:
                code_and_words[code].append(x)
            else:
                code_and_words[code] = [x]
            
        
        for code in code_and_words:
            return_list.append(code_and_words[code])
        
        return return_list
