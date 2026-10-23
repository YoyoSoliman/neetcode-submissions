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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while (p1 != nullptr and p2 != nullptr) {
            if (p1->val <= p2->val) {
                ListNode* saved = p1->next;
                p1->next = nullptr;
                curr->next = p1;
                curr = curr->next;
                p1 = saved;
            } else {
                ListNode* saved = p2->next;
                p2->next = nullptr;
                curr->next = p2;
                curr = curr->next;
                p2 = saved;
            }
        }
        if (p2 != nullptr) {
            curr->next = p2;
        }

        if (p1 != nullptr) {
            curr->next = p1;
        }

        return dummy->next;


    }
};
