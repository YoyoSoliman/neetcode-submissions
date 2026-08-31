class MinStack {
private:
    vector<int> s;
    vector<int> minS;
public:
    MinStack() {}
    
    void push(int val) {
        if (s.empty()) {
            s.push_back(val);
            minS.push_back(val);    
        } else {
            s.push_back(val);
            minS.push_back(min(val,minS.back()));
        }
    }
    
    void pop() {
        s.pop_back();
        minS.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return minS.back();
    }
};
