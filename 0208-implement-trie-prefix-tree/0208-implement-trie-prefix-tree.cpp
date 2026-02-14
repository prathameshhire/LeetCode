class TrieNode {
public:
    TrieNode* children[26];
    char data;
    bool isTerminal;

    TrieNode() {
        for (int i = 0; i<26; i++) {
            children[i] = NULL;
        }
    }
    TrieNode(char data) {
        this->data = data;
        for (int i = 0; i<26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};


class Trie {
public: 
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        insertUtil(word, root);
    }

    void insertUtil(string word, TrieNode* root) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'a';

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(word.substr(1), child);
    }
    
    bool search(string word) {
        return searchUtil(word,root);
    }

    bool searchUtil(string word, TrieNode* root) {
        if (word.length() == 0) return root->isTerminal;

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        }

        else return false;
        return searchUtil(word.substr(1), child);
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c:prefix) {
            int index = c - 'a';
            if (cur->children[index] == NULL) {
                return false;
            }
            cur = cur->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */