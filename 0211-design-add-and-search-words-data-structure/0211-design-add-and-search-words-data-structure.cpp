class WordDictionary {
public:

    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
    
    };

    trieNode* createNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        for (int i = 0; i<26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;

    WordDictionary() {
        root = createNode();
    }
    
    void addWord(string word) {
        trieNode* crawler = root;
        for (int i = 0; i<word.length(); i++) {
            int index = word[i] - 'a';

            if (crawler->children[index] == NULL) {
                crawler->children[index] = createNode();
            }

            crawler = crawler->children[index];
        }

        crawler->isEndOfWord = true;
    }
    
    bool searchUtil(trieNode* root, string word) {
        trieNode* crawler = root;
        for (int i = 0; i<word.length(); i++) {
            char ch = word[i];
            
            if (ch == '.') {
                for (int j = 0; j<26; j++) {
                    if (crawler->children[j] != NULL) {
                        if (searchUtil(crawler->children[j], word.substr(i+1)) == true) return true;
                    }
                }
                return false;
            }


            int index = ch-'a';
            if (crawler->children[index] == NULL) return false;

            crawler = crawler->children[index]; 
        }

        return (crawler->isEndOfWord);
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */