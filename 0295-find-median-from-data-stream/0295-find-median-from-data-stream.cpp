class MedianFinder {
public:
    priority_queue<int> maxLeft;
    priority_queue<int, vector<int>, greater<int>> minRight;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxLeft.empty() || num < maxLeft.top()) maxLeft.push(num);
        else minRight.push(num);
        if(maxLeft.size() > minRight.size() + 1) {
            minRight.push(maxLeft.top());
            maxLeft.pop();
        }
        else if(minRight.size() > maxLeft.size()) {
            maxLeft.push(minRight.top());
            minRight.pop();
        }
    }
    
    double findMedian() {
        if(maxLeft.size() == minRight.size()) {
            return (maxLeft.top() + minRight.top())/2.0;
        }
        else return maxLeft.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */