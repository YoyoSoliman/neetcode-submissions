# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:

        count = 0
        curr_node = head
        stack = []

        while curr_node:
            count+=1
            curr_node = curr_node.next       

        index=0
        curr_node = head
        node_to_change = None

        while curr_node:
            if index > count // 2:
                stack.append(curr_node)
            if index == count // 2:
                node_to_change = curr_node
            curr_node = curr_node.next
            index+=1

        if node_to_change:
            node_to_change.next = None
        curr_node = head

        while stack:

            temp_next = curr_node.next

            act_next = stack.pop()

            curr_node.next = act_next
            act_next.next = temp_next

            curr_node = temp_next
