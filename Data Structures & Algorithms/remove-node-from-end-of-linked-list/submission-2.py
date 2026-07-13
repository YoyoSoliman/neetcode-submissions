# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        stack = []
        curr=head
        ret = None
        while curr:
            stack.append(curr)
            curr=curr.next
        
        node_to_remove = None

        for i in range(0,n):
            node_to_remove = stack.pop()
        
        print(node_to_remove.val)
        if stack:
            node_before = stack.pop()

            node_before.next = node_to_remove.next
            node_to_remove.next = None
            ret = head
        else:
            ret = head.next
    
        return ret




        

