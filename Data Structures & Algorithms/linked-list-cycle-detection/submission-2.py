# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        
        if head == None:
            return False
            
        fastPointer = head
        slowPointer = head

        while fastPointer != None:
            if fastPointer.next != None:
                fastPointer = fastPointer.next
                if fastPointer.next != None:
                    fastPointer = fastPointer.next
                else:
                    return False
            else:
                return False
            slowPointer = slowPointer.next
        

            if slowPointer == fastPointer:
                return True

        