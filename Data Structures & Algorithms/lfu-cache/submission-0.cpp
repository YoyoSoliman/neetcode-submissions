#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int val;
    int freq;

    Node* prev;
    Node* next;

    // Fixed constructor initialization list
    Node(int k, int v, int f) : key(k), val(v), freq(f), prev(nullptr), next(nullptr) {}
};

class LFUCache {
public:
    unordered_map<int, Node*> keyToNode;
    int cap;
    Node* lfu; // Dummy head
    Node* mfu; // Dummy tail

    LFUCache(int capacity) {
        cap = capacity;
        lfu = new Node(-1, -1, 0);
        mfu = new Node(-1, -1, 0);
        
        // Connect sentinel head and tail inside constructor
        lfu->next = mfu;
        mfu->prev = lfu;
    }
    
    // Helper function to shift a node forward while its frequency is >= next node's frequency
    void shiftUp(Node* curr) {
        while (curr->next != mfu && curr->freq >= curr->next->freq) {
            Node* nxt = curr->next;
            Node* prev = curr->prev;
            Node* nxt_next = nxt->next;

            // Re-link surrounding pointers
            prev->next = nxt;
            nxt->prev = prev;

            nxt->next = curr;
            curr->prev = nxt;

            curr->next = nxt_next;
            nxt_next->prev = curr;
        }
    }

    int get(int key) {
        if (!keyToNode.count(key)) {
            return -1;
        }

        Node* curr = keyToNode[key];
        curr->freq++;

        // Bubble node forward as frequency increases
        shiftUp(curr);

        return curr->val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        // Case 1: Key already exists
        if (keyToNode.count(key)) {
            Node* curr = keyToNode[key];
            curr->val = value;
            curr->freq++;

            shiftUp(curr);
            return;
        }

        // Case 2: Cache is full -> Evict node at lfu->next (least frequent)
        if (keyToNode.size() >= cap) {
            Node* nodeToRemove = lfu->next;
            
            // Unlink nodeToRemove
            lfu->next = nodeToRemove->next;
            nodeToRemove->next->prev = lfu;

            keyToNode.erase(nodeToRemove->key);
            delete nodeToRemove; // Avoid memory leak
        }

        // Case 3: Insert new node with freq = 1 right after lfu
        Node* n = new Node(key, value, 1);
        Node* saved = lfu->next;

        lfu->next = n;
        n->prev = lfu;

        n->next = saved;
        saved->prev = n;

        keyToNode[key] = n;

        // Shift up if needed (in case lfu->next already had higher frequency nodes)
        shiftUp(n);
    }
};