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
                stack.append(i)
            elif i == '-':
                first = int(stack[len(stack)-1])
                second = int(stack[len(stack)-2])
                stack.pop()
                stack.pop()
                stack.append(second-first)   
            elif i == '+':
                first = int(stack[len(stack)-1])
                second = int(stack[len(stack)-2]) 
                stack.pop()
                stack.pop()
                stack.append(first+second)   
            elif i == '*':
                first = int(stack[len(stack)-1])
                second = int(stack[len(stack)-2]) 
                stack.pop()
                stack.pop()
                stack.append(second*first)
            else:
                first = int(stack[len(stack)-1])
                second = int(stack[len(stack)-2])
                stack.pop()
                stack.pop()
                stack.append(second/first)
            print(stack)
        


        return int(stack[0])