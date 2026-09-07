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
    ListNode* middleNode(ListNode* head) {
        int size = 0;

        ListNode* p = head;

        while (p != nullptr) {
            size++;
            p = p->next;
        }
        ListNode* slowP = head;
        ListNode* fastP = head;

        while (fastP->next != nullptr && fastP->next->next != nullptr) {
            fastP = fastP->next->next;
            slowP = slowP->next;
        }

        if (size % 2 == 1) {
            return slowP;
        } else {
            return slowP->next;
        }
        
    }
};