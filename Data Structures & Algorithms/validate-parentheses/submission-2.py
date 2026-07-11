from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
        stack = deque()

        for par in s:
            if par in "({[":
                stack.append(par)
            else:
                if not stack:
                    return False
                if par == ')' and stack[-1] != '(':
                    return False
                if par == '}' and stack[-1] != '{':
                    return False
                if par == ']' and stack[-1] != '[':
                    return False
                stack.pop()
            
        
        if not stack:
            return True
        else:
            return False


        