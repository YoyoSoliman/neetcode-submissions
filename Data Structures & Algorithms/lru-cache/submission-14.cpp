#include <unordered_map>

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k = 0, int v = 0) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, Node*> m;
    Node* head; // Dummy head (MRU side)
    Node* tail; // Dummy tail (LRU side)

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!m.count(key)) {
            return -1;
        }

        Node* node = m[key];
        remove(node);
        insertAtHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (m.count(key)) {
            Node* node = m[key];
            node->val = value;
            remove(node);
            insertAtHead(node);
            return;
        }

        if (m.size() == capacity) {
            Node* lru = tail->prev; 
            m.erase(lru->key);
            remove(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        m[key] = newNode;
        insertAtHead(newNode);
    }
};