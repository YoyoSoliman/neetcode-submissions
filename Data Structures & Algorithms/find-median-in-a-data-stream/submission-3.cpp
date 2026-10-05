class MedianFinder {
public:

    //have minHeap that holds the to half of values
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    //have maxHeap that holds the smaller values
    priority_queue<int> maxHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if (num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();

        }


        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop(); 
        }
    }
    
    double findMedian() {
        double res = 0;

        if (maxHeap.size() == minHeap.size()) {
            res = (static_cast<double>(maxHeap.top()) + static_cast<double>(minHeap.top())) /2;
        } else if (maxHeap.size() > minHeap.size()) {
            res = maxHeap.top();
        } else {
            res = minHeap.top();
        }

        return res;
    }
};
