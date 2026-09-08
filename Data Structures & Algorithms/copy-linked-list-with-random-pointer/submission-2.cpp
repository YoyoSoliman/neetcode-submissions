/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*,Node*> realToCopy;

        Node* original = head;
        Node* dummy = new Node(0);
        Node* prev = dummy;

        /*dummy -> 3->

          prev*/

        while (original != nullptr) {
            if (!realToCopy.count(original)) {
                Node* n = new Node(original->val);
                realToCopy[original] = n;

                prev->next = n;
                prev = realToCopy[original];
                if (original->random != nullptr) {
                    if (realToCopy.count(original->random)) {
                        n->random = realToCopy[original->random];
                    } else {
                        Node* m = new Node(original->random->val);
                        realToCopy[original->random] = m;
                        n->random = m;
                    }
                } 
            } else {
                prev->next = realToCopy[original];
                prev = realToCopy[original];
                if (original->random != nullptr) {
                    if (realToCopy.count(original->random)) {
                        realToCopy[original]->random = realToCopy[original->random];
                    } else {
                        Node* m = new Node(original->random->val);
                        realToCopy[original->random] = m;

                        realToCopy[original]->random = m;
                    }
                } 
            }

            original = original->next;
        } 

        return dummy->next;
    }
};
