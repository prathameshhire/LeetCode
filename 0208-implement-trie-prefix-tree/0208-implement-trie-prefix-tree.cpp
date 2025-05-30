class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode() {
        for (int i = 0; i<26; i++) {
            children[i] = NULL;
        }
    }

    TrieNode(char ch) {
        data = ch;
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
    
    void insertUtil(TrieNode* &root, string word) {
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
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }
    
    bool searchUtil(TrieNode* &root, string word) {
        if (word.length() == 0) return root->isTerminal;

        TrieNode* child;
        int index = word[0] - 'a';

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else return false;
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c: prefix) {
            int index = c-'a';
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