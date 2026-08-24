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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        std::priority_queue<
        std::pair<int, ListNode*>, 
        std::vector<std::pair<int, ListNode*>>, 
        std::greater<std::pair<int, ListNode*>>
    > min_heap;


        for (ListNode* node : lists) {
            if (node != nullptr) {
                min_heap.push({node->val,node});
            }
        }

        while (!min_heap.empty()) {
            int val = min_heap.top().first;
            ListNode* n = min_heap.top().second;
            curr->next = n;
            min_heap.pop();
            if (n->next != nullptr) {
                min_heap.push({n->next->val,n->next});
            }
            curr = curr->next;
        }


        return dummy->next;
    }
};
