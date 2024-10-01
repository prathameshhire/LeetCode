class CustomStack {
public:
    int maxSize;
    int currSize;
    vector <int> stack;
    CustomStack(int maxSize) {
        this -> maxSize = maxSize;
        currSize=0;
    }
    
    void push(int x) {
        if (currSize == maxSize) {
            return;
        }
        stack.push_back(x);
        currSize++;
    }
    
    int pop() {
        if (currSize == 0) {
            return -1;
        }
        int top = stack.back();
        stack.pop_back();
        currSize--;
        return top;
    }
    
    void increment(int k, int val) {
        for (int i=0; i < min(currSize,k); i++) {
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */