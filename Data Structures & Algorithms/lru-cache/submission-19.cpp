struct ListNode{
    ListNode* next;
    ListNode* prev;
    int val;
    int key;
};
// lru <-> mru
class LRUCache {
public:
    int cap = 0;
    ListNode* lru = new ListNode();
    ListNode* mru = new ListNode();
    unordered_map<int,ListNode*> key_to_node;

    LRUCache(int capacity) {
        cap = capacity;
        mru->prev = lru;
        lru->next = mru;
    }
    
    int get(int key) {

        if (!key_to_node.count(key)) {
            return -1;
        }
        ListNode* n = key_to_node[key];
        int value = n->val;

        ListNode* before_n = n->prev;
        ListNode* after_n = n->next;

        before_n->next = nullptr; 
        after_n->prev = nullptr;

        before_n->next = after_n;
        after_n->prev = before_n;

        ListNode* saved = mru->prev;

        mru->prev = n;
        n->next = mru;
        n->prev = saved;
        saved->next = n;

        return value;
    }
    
    void put(int key, int value) {

        if (key_to_node.count(key)) {
            ListNode* n = key_to_node[key];
            n->val = value;

            ListNode* before_n = n->prev;

            ListNode* after_n = n->next;

            before_n->next = nullptr; 
            after_n->prev = nullptr;

            before_n->next = after_n;
            after_n->prev = before_n;

            ListNode* saved = mru->prev;

            mru->prev = n;
            n->next = mru;
            n->prev = saved;
            saved->next = n;
            return;
        }

        if (key_to_node.size() >= cap) {
            ListNode* least_recently_used_node = lru->next;

            lru->next = least_recently_used_node->next;
            least_recently_used_node->next->prev = lru;

            least_recently_used_node->next = nullptr;
            least_recently_used_node->prev = nullptr;

            key_to_node.erase(least_recently_used_node->key);
        }

        ListNode* n = new ListNode();
        ListNode* prev_most_used = mru->prev;

        n->key = key;
        n->val = value;

        prev_most_used->next = n;
        n->prev = prev_most_used;

        n->next = mru;
        mru->prev = n;

        key_to_node[key] = n;

        return;
    }
};
