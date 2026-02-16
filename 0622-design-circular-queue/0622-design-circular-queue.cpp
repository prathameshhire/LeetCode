class MyCircularQueue {
public:
    struct listNode {
        int val;
        listNode *next;
        listNode *prev;
        listNode(int v, listNode* n = nullptr, listNode* p=nullptr) {
            val = v;
            next = n;
            prev = p;
        }

    };

    int space;
    listNode* right;
    listNode* left;


    MyCircularQueue(int k) {
        left = new listNode(0);
        right = new listNode(0,nullptr, left);
        left->next = right;
        space = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        listNode * curr = new listNode(value, right, right->prev);
        right->prev->next = curr;
        right->prev = curr;
        space--;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        listNode* curr = left->next;
        left->next = left->next->next;
        curr->next->prev = left;
        delete(curr);
        space++;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : left->next->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : right->prev->val;
    }
    
    bool isEmpty() {
        return left->next == right;
    }
    
    bool isFull() {
        return space == 0;
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