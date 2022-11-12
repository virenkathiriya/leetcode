class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxpq.push(num);
        minpq.push(maxpq.top());
        maxpq.pop();
        if (minpq.size() > maxpq.size()) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        return (minpq.size() == maxpq.size()) ? (minpq.top() + maxpq.top()) / 2.0 : maxpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */