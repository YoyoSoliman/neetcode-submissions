class MinStack:
    def __init__(self):
        self.l=[]
        self.minStack = []
        self.size=-1

    def push(self, val: int) -> None:

        self.l.append(val)
        if self.size < 0:
            self.minStack.append(val)
        else: 
            if val < self.minStack[self.size]:
                self.minStack.append(val)
            else:
                self.minStack.append(self.minStack[self.size])
        self.size+=1

    def pop(self) -> None:
        if self.size >= 0:
            self.l.pop()
            self.minStack.pop()
            self.size-=1

    def top(self) -> int:
        if self.size >=0: 
            return self.l[self.size] 

    def getMin(self) -> int:
        return self.minStack[self.size]

