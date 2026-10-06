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
    /*
    0->1->2->3->4->5->6


    0->6->1->5->2->4->3
    */

    /*


    */
    ListNode* reverseList(ListNode* c) {
        ListNode* prev = nullptr;
        ListNode* curr = c;

        while (curr != nullptr) {
            ListNode* saved = curr->next;
            curr->next = prev;

            prev = curr;
            curr = saved;
        }
        return prev;

    }

    void reorderList(ListNode* head) {


        ListNode* fPointer = head;
        ListNode* sPointer = head;

        while (fPointer->next != nullptr and fPointer->next->next != nullptr) {
            fPointer = fPointer->next->next;
            sPointer = sPointer->next;
        }

        ListNode* secondHalf = sPointer->next;
        sPointer->next = nullptr;

        ListNode* p2 = reverseList(secondHalf);

        ListNode* p1 = head;
        
        while (p1 != nullptr and p2 != nullptr) {
            ListNode* saved1 = p1->next;
            ListNode* saved2 = p2->next;

            p1->next = p2;
            p2->next = saved1;

            p1 = saved1;
            p2 = saved2;
        }
    }
};
