# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        #Keep trakc of current node and the last node
        curr_node = head
        last_node = None

        #while a current node exists
        while curr_node:
            
            temp_next = curr_node.next
            curr_node.next = last_node
            last_node = curr_node
            curr_node = temp_next
            
            

        return last_node


        #0 --> 1 ---> 2 ---> 3

        #curr = 0
        #next = 1

        