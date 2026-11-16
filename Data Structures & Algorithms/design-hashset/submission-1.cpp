class MyHashSet {
public:
    std::vector<bool> st;
    MyHashSet() {
        st.resize(10000000,false);
    }
    
    void add(int key) {
        st[key] = true;
    }
    
    void remove(int key) {
        st[key] = false;
    }
    
    bool contains(int key) {
        bool res = st[key];
        return res;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */