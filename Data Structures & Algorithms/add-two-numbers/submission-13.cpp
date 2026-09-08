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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int value1 = 0;
            int value2 = 0;

            if (l1!=nullptr) {
                value1=l1->val;
            }

            if (l2!=nullptr) {
                value2=l2->val;
            }
           
            if (value1 + value2 + carry < 10) {
                
                ListNode* n = new ListNode(value1 + value2 + carry);
                carry = 0;
                curr->next = n;
            } else {
                ListNode* n = new ListNode((value1+value2+carry) % 10);
                carry = 1;
                curr->next = n;
            }

            curr = curr->next;

            if(l1!=nullptr) {
                l1 = l1->next;
            }

            if (l2!=nullptr) {
                l2 = l2->next;
            }


        }

        if (carry != 0) {
            ListNode* n = new ListNode(1);
            curr->next = n;
        }

        return dummy->next;
    }
};
