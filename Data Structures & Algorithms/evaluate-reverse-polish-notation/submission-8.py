class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        #if we have two stacks one for numebrs one for divsion/sub

        stack = []
        def is_number(s):
            try:
                int(s)
                return True
            except ValueError:
                return False

        for i in tokens:
            if is_number(i):
                stack.append(int(i))
            elif i == '-':
                first = stack[len(stack)-1]
                second = stack[len(stack)-2]
                stack.pop()
                stack.pop()
                stack.append(second-first)   
            elif i == '+':
                first = stack[len(stack)-1]
                second = stack[len(stack)-2]
                stack.pop()
                stack.pop()
                stack.append(first+second)   
            elif i == '*':
                first = stack[len(stack)-1]
                second = stack[len(stack)-2]
                stack.pop()
                stack.pop()
                stack.append(second*first)
            else:
                first = stack[len(stack)-1]
                second = stack[len(stack)-2]
                stack.pop()
                stack.pop()
                stack.append(int(second/first))        

        return int(stack[0])