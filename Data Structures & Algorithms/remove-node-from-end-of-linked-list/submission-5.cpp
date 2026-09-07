/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size_of_list = 0;
        ListNode* curr = head; 
        ListNode* dummy = new ListNode();

        dummy->next = head;

        while (curr != nullptr) {
            size_of_list++;
            curr = curr->next;
        }

        ListNode* prev = dummy;
        curr = head;
        for (int i = 0; i < size_of_list-n;i++) {
            prev = curr;
            curr = curr->next;
        }

        ListNode* saved = curr->next;
        curr->next = nullptr;
        prev->next = saved;

        return dummy->next;
        
    }
};
