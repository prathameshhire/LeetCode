class MyCircularQueue {
public:
    vector<int> q;
    int capacity;
    MyCircularQueue(int k) {
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (q.size() == capacity) return false;
        else{
            q.push_back(value);
            return true;
        }
    }
    
    bool deQueue() {
        if (!q.empty()) {
            q.erase(q.begin());
            return true;
        }
        return false;
    }
    
    int Front() {
        return q.empty() ? -1 : q.front();
    }
    
    int Rear() {
        return q.empty() ? -1 : q.back();        
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return capacity == q.size() ? true : false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */