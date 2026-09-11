class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k = 0, int v = 0) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:

    unordered_map<int,Node*> m;
    int cap = 0;
    Node* mru = new Node(-1,-1);
    Node* lru = new Node(-1,-1);

    LRUCache(int capacity) {

        cap = capacity;
        mru->next = lru;
        lru->prev = mru;

    }
    
    int get(int key) {
        if (!m.count(key)) {
            return -1;
        } 

        Node* saved1 = m[key]->prev;
        Node* saved2 = m[key]->next;

        m[key]->next = nullptr;
        m[key]->prev = nullptr;

        saved1->next = saved2;
        saved2->prev = saved1;

        Node* saved3 = mru->next;
        mru->next = m[key];
        m[key]->next = saved3;
        saved3->prev = m[key];
        m[key]->prev = mru;

        return m[key]->val;

    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            Node* saved1 = m[key]->prev;
            Node* saved2 = m[key]->next;

            m[key]->next = nullptr;
            m[key]->prev = nullptr;

            saved1->next = saved2;
            saved2->prev = saved1;

            Node* saved3 = mru->next;
            mru->next = m[key];
            m[key]->next = saved3;
            saved3->prev = m[key];

            m[key]->prev = mru;

            m[key]->val = value;
        } else {
            Node* n = new Node(key,value);

            m[key] = n;

            Node* saved = mru->next;
            mru->next = n;
            n->next = saved;
            saved->prev = n;
            n->prev = mru;
        }

        if (m.size() > cap) {
            m.erase(lru->prev->key);
            lru->prev->prev->next = lru;
            lru->prev = lru->prev->prev;
        }
    }
};
