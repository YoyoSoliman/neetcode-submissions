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
        ListNode* dummy = new ListNode(0);

        ListNode* curr = dummy;

        using HeapElement = std::pair<int, ListNode*>;
    
        std::priority_queue<
            HeapElement, 
            std::vector<HeapElement>, 
            std::greater<HeapElement>
        > minHeap;

        for (ListNode* n: lists) {
            if (n!=nullptr) {
                minHeap.push({n->val,n});
            }
        }

        while (!minHeap.empty()) {
            auto [val, node] = minHeap.top();
            minHeap.pop();

            if (node->next != nullptr) {
                minHeap.push({node->next->val,node->next});
            }
            node->next = nullptr;
            curr->next = node;
            curr = curr->next;
        }

        return dummy->next;
    }
};
