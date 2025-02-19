class MyHashSet {
private:
    struct ListNode {
        int key;
        ListNode* next;
        ListNode(int k) : key(k), next(nullptr) {}
    };

    vector<ListNode*> set;

    int hash (int key) {
        return key%set.size();
    }

public:
    MyHashSet() {
        set.resize(10000);
        for (auto &list:set) {
            list = new ListNode(0);
        }
    }
    
    void add(int key) {
        ListNode* cur = set[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                return;
            }
            cur = cur->next;
        }
        cur->next = new ListNode(key);
    }
    
    void remove(int key) {
        ListNode* cur = set[hash(key)];
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
    
    bool contains(int key) {
        ListNode* cur = set[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */