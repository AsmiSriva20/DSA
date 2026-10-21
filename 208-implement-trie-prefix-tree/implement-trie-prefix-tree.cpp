class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for(char c : word) {
            int i = c - 'a';

            if(node->children[i] == NULL)
                node->children[i] = new TrieNode();

            node = node->children[i];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for(char c : word) {
            int i = c - 'a';

            if(node->children[i] == NULL)
                return false;

            node = node->children[i];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for(char c : prefix) {
            int i = c - 'a';

            if(node->children[i] == NULL)
                return false;

            node = node->children[i];
        }

        return true;
    }
};