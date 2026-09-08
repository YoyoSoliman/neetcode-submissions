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

/*Two pass solution*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        unordered_map<Node*,Node*> realToCopy;

        while (curr != nullptr) {
            Node* n = new Node(curr->val);

            realToCopy[curr] = n;
            curr = curr->next;
        }

        curr=head;

        while (curr != nullptr) {
            realToCopy[curr]->next = realToCopy[curr->next];
            realToCopy[curr]->random = realToCopy[curr->random];

            curr = curr->next;
        }

        return realToCopy[head];

    }
};
