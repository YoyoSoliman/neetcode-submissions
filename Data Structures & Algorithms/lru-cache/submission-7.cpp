#include <unordered_map>

class Node {
public:
    int key;
    Node* next;

    Node(int k = 0) : key(k), next(nullptr) {}
};

class LRUCache {
public:
    Node* mru = new Node(); 
    int cap = 0;
    std::unordered_map<int, int> m;

    LRUCache(int capacity) {
        cap = capacity;
        mru->key = -1;
    }
    
    int get(int key) {
        if (!m.count(key)) {
            return -1;
        }

        Node* curr = mru->next;
        Node* prev = mru;

        // Find the node
        while (curr != nullptr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }

        // Move to front only if it isn't already at the front
        if (curr != nullptr && prev != mru) {
            prev->next = curr->next;  // Bypass curr
            curr->next = mru->next;   // Put curr at front
            mru->next = curr;
        }
        
        return m[key];
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            m[key] = value; // Update value in map
            
            // Move node to front (same logic as get)
            Node* curr = mru->next;
            Node* prev = mru;

            while (curr != nullptr && curr->key != key) {
                prev = curr;
                curr = curr->next;
            }

            if (curr != nullptr && prev != mru) {
                prev->next = curr->next;
                curr->next = mru->next;
                mru->next = curr;
            }

        } else {
            m[key] = value;
            
            // Insert new node at the front
            Node* n = new Node(key);
            n->next = mru->next;
            mru->next = n;

            // Evict the tail node if over capacity
            if (m.size() > cap) {
                Node* curr = mru;
                Node* prev = nullptr;

                // Traverse to the end of the list
                while (curr->next != nullptr) {
                    prev = curr;
                    curr = curr->next;
                }

                prev->next = nullptr;
                m.erase(curr->key);
                delete curr; // Free memory
            }
        }
    }
};