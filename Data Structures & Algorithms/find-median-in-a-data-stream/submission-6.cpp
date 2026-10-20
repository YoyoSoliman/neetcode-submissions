class MedianFinder {
public:
    
    std::priority_queue<int> smaller_half;
    std::priority_queue<int, std::vector<int>, std::greater<int>> larger_half;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smaller_half.empty()) {
            smaller_half.push(num);
            return;
        }

        if (num <= smaller_half.top()) {
            smaller_half.push(num);
        } else {
            larger_half.push(num);
        }

        int smaller_half_size = smaller_half.size();
        int larger_half_size = larger_half.size();

        if (smaller_half_size - larger_half_size > 1) {
            larger_half.push(smaller_half.top());
            smaller_half.pop();
        }


        if (larger_half_size - smaller_half_size > 1) {
            smaller_half.push(larger_half.top());
            larger_half.pop();
        }
    }
    
    double findMedian() {
        int smaller_half_size = smaller_half.size();
        int larger_half_size = larger_half.size();
        if (smaller_half_size == larger_half_size) {
            return (static_cast<double>(smaller_half.top()) + larger_half.top()) / 2.0;
        } else if (smaller_half.size() > larger_half.size()) {
            return static_cast<double>(smaller_half.top());
        } else {
            return static_cast<double>(larger_half.top());
        }
    }
};
