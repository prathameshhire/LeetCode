class MyHashMap {
private:
    struct ListNode {
        int key, val;
        ListNode* next;

        ListNode(int key = -1, int val = -1, ListNode* next = nullptr) : key(key), val(val), next(next) {}
    };

    vector<ListNode*> map;
    int hash(int key) {
        return key%map.size();
    }

public:
    MyHashMap() {
        map.resize(1000);
        for (auto &list: map) {
            list = new ListNode(0);
        }
    }
    
    void put(int key, int value) {
        ListNode* cur = map[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                cur->next->val = value;
                return;
            }
            cur = cur->next;
        }
        cur->next = new ListNode(key,value);
    }
    
    int get(int key) {
        ListNode* cur = map[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                return cur->next->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* cur = map[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                delete temp;
                return;
            }
            cur = cur->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */