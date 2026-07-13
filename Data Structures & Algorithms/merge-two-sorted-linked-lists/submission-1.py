# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        
        pointer1 = list1
        pointer2 = list2

        if pointer1 == None and pointer2 != None:
            start_node = pointer2
            pointer2 = pointer2.next
        elif pointer1 != None and pointer2 == None: 
            start_node = pointer1
            pointer1 = pointer1.next
        elif pointer1 == None and pointer2 == None:
            start_node = None
        else:
            if pointer1.val < pointer2.val:
                start_node = pointer1
                pointer1 = pointer1.next
            else:
                start_node = pointer2
                pointer2 = pointer2.next


        
        curr_node=start_node

        while pointer1 != None or pointer2 != None:
            if pointer1 == None:
                curr_node.next = pointer2
                pointer2 = pointer2.next
                curr_node = curr_node.next
            elif pointer2 == None:
                curr_node.next = pointer1
                pointer1 = pointer1 .next
                curr_node = curr_node.next
            else:
                if pointer1.val < pointer2.val:
                    curr_node.next = pointer1
                    pointer1 = pointer1 .next
                    curr_node = curr_node.next
                else:
                    curr_node.next = pointer2
                    pointer2 = pointer2.next
                    curr_node = curr_node.next
        
        return start_node

