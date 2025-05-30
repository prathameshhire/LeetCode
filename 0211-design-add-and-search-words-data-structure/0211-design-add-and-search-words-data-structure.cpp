class TrieNode {
public:
    vector<TrieNode*> children;
    bool isTerminal;
    TrieNode() : children(26, nullptr) , isTerminal(false) {}
};


class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode* cur = root; 
        for (char c: word) {
            if (cur->children[c-'a'] == nullptr) {
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur->isTerminal = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* cur = root;
        for (int i = j; i<word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (TrieNode* child : cur->children) {
                    if (child!=nullptr && dfs(word, i+1, child)) return true;
                }
                return false;
            }
            else {
                if (cur->children[c-'a'] == nullptr) return false;
                else cur = cur->children[c-'a'];
            }
        }
        return cur->isTerminal;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */