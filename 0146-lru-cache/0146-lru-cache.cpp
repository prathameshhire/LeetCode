class LRUCache {
public:

    class Node {
        public:
            int key;
            int val;
            Node * next;
            Node * prev;
            Node(int _key, int _val) {
                key = _key;
                val = _val;
            }
    };

    unordered_map<int, Node*> mpp;
    Node* tail = new Node(-1,-1);
    Node* head = new Node(-1,-1);
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node* node) {
        Node* behind = node->prev;
        Node* ahead = node->next;
        behind->next = ahead;
        ahead->prev = behind;
    }

    void insertHead(Node* newnode) {
        Node* temp = head -> next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertHead(node);
        }
        else {
            if (mpp.size() == cap) {
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* newnode = new Node (key, value);
            mpp[key] = newnode;
            insertHead(newnode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */