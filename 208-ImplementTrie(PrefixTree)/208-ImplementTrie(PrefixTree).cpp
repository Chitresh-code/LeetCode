class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(const string& word, int index, TrieNode* root) {
        if (index == word.length()) {
            root->isTerminal = true;
            return;
        }

        int charIndex = word[index] - 'a';
        if (root->children[charIndex] == nullptr) {
            root->children[charIndex] = new TrieNode(word[index]);
        }

        insertUtil(word, index + 1, root->children[charIndex]);
    }

    void insert(const string& word) {
        insertUtil(word, 0, root);
    }

    bool searchUtil(const string& word, int index, TrieNode* root) const {
        if (index == word.length()) {
            return root->isTerminal;
        }

        int charIndex = word[index] - 'a';
        if (root->children[charIndex] == nullptr) {
            return false;
        }

        return searchUtil(word, index + 1, root->children[charIndex]);
    }

    bool search(const string& word) const {
        return searchUtil(word, 0, root);
    }

    bool startsWithUtil(const string& prefix, int index, TrieNode* root) const {
        if (index == prefix.length()) {
            return true;
        }

        int charIndex = prefix[index] - 'a';
        if (root->children[charIndex] == nullptr) {
            return false;
        }

        return startsWithUtil(prefix, index + 1, root->children[charIndex]);
    }

    bool startsWith(const string& prefix) const {
        return startsWithUtil(prefix, 0, root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */