#include <unordered_map>

class Node {
public:
    int key; 
    int val;
    Node* next;

    Node(int k = 0, int v = 0) : key(k), val(v), next(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    int currentSize = 0;
    Node* dummy = new Node(-1, -1);
    std::unordered_map<int, int> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (!cache.contains(key)) {
            return -1;
        }

        Node* prev = dummy;       
        Node* curr = dummy->next;  
        Node* mru = nullptr;

        while (curr != nullptr) {
            if (curr->key == key) {
                mru = curr;
                if (curr->next == nullptr) {
                    break; 
                }
                prev->next = curr->next;
                curr = curr->next; 
                mru->next = nullptr;
                continue;        
            }
            prev = curr;
            curr = curr->next;
        }

        if (mru != nullptr) {
            prev->next = mru; 
        }

        return cache[key];
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            cache[key] = value;
            get(key); 
        } else {
            currentSize++;
            Node* curr = dummy;
            Node* mru = new Node(key, value);

            while (curr->next != nullptr) {
                curr = curr->next;
            }

            curr->next = mru;
            cache[key] = value;
        }

        if (currentSize > capacity) {
            Node* lru = dummy->next;
            int keyToRemove = lru->key; 
            dummy->next = lru->next;
            delete lru;                 
            cache.erase(keyToRemove);
            currentSize--;
        }
    }
};