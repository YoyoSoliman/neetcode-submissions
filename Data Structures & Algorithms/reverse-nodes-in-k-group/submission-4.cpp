class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* lastSection = dummy;

        while (true) {

            ListNode* curr = lastSection->next;
            int count = 0;
            while (curr != nullptr && count < k) {
                curr = curr->next;
                count++;
            }

            if (count < k) {
                break;
            }

            ListNode* curr1 = lastSection->next;
            ListNode* prev = curr; 
            
            while (curr1 != curr) {
                ListNode* saved = curr1->next;
                curr1->next = prev;
                prev = curr1;
                curr1 = saved;
            }

            ListNode* oldGroupStart = lastSection->next;

            lastSection->next = prev;

            lastSection = oldGroupStart;
        }

        return dummy->next;
    }
};