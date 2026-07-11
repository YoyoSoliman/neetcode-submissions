class MinStack:
    def __init__(self):
        self.l=[]
        self.size=-1

    def push(self, val: int) -> None:
        self.l.append(val)
        self.size+=1

    def pop(self) -> None:
        if self.size >= 0:
            del self.l[self.size]
            self.size-=1

    def top(self) -> int:
        if self.size >=0: 
            return self.l[self.size] 

    def getMin(self) -> int:
        m = self.l[0]
        for i in self.l:
            if m > i:
                m = i
        
        return m

