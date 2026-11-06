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
    int findGreatestCommon(int n1,int n2) {
        for (int i = max(n1,n2);i >= 1;i--) {
            if (n1 % i == 0 and n2 % i ==0){
                return i;
            }
        }
        return -1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* saved = nullptr;

        while (curr->next != nullptr) {
            saved = curr->next;
            ListNode* n = new ListNode(findGreatestCommon(curr->val,saved->val));
            curr->next = n;
            n->next = saved;
            curr = saved;
        }

        return head;
    
    }
};