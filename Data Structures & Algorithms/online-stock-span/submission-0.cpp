class StockSpanner {
public:
    vector<int> p;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (p.empty()) {
            p.push_back(price);
            return 1;
        }

        int res = 1;
        for (int i = p.size()-1; i>=0;i--) {
            if (p[i] <= price) {
                res++;
            } else {
                break;
            }
        }

        p.push_back(price);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */