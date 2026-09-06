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
    bool hasCycle(ListNode* head) {
        if (head->next == nullptr || head==nullptr) {
            return false;
        }

        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        while (fastPointer != nullptr) {

            if (fastPointer->next != nullptr and fastPointer->next->next != nullptr) {
                fastPointer = fastPointer->next->next;
            } else {
                return false;
            }

            slowPointer = slowPointer->next;

            if (fastPointer == slowPointer) {
                return true;
            }
        }

        return false;
    }
};
