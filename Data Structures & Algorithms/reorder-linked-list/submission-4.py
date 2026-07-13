# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:

        fastPointer = head
        slowPointer = head

        while fastPointer.next and fastPointer.next.next:
            fastPointer = fastPointer.next.next
            slowPointer = slowPointer.next
        
        prev=None
        secondhalf = slowPointer.next
        slowPointer.next = None
        curr = secondhalf

        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        
        first = head
        second = prev

        while second:
            tmp1 = first.next
            tmp2 = second.next

            first.next = second
            second.next = tmp1

            first = tmp1
            second = tmp2



