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
    void reorderList(ListNode* head) {
        ListNode* p2 = head;
        ListNode* p1 = head;

        while (true) {
            if (p2->next != nullptr and p2->next->next != nullptr) {
                p2 = p2->next->next;
                p1 = p1 -> next;
            } else {
                break;
            }
        }

    
        p2= p1->next;
        p1->next = nullptr;
        p1 = head;

        ListNode* prev = nullptr;

        while (p2 != nullptr) {
            ListNode* saved = p2->next;
            p2->next= prev;
            prev = p2;
            p2 = saved;
        }

        ListNode* dummy = new ListNode();
        p2 = prev;
        ListNode* curr = dummy;

        while (p1 != nullptr and p2 != nullptr) {
            ListNode* saved = p1->next;
            p1->next = nullptr;
            curr->next = p1;
            p1 = saved;
            curr = curr->next;

            saved = p2->next;
            p2->next = nullptr;
            curr->next = p2 ;
            p2 = saved;
            curr = curr->next;
        }

        if (p1!= nullptr) {
            curr->next = p1;
        }

    }
};
