#include <iostream>
#include <string>
using namespace std;

class Trie {
    struct Node {
        bool isWord;
        Node* next[26];
        Node(bool b = false) {
            memset(next, 0, sizeof(next));
            isWord = b;
        }
    };
    Node* root;
    public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.length()==0) root->isWord = true;
        Node* idx = root;
        for(int i = 0; i<word.size(); i++) {
            int target = word[i] - 'a';
            if(!idx->next[target]) idx->next[target] = new Node();
            idx = idx->next[target];
        }
        idx->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.length()==0) return root->isWord;
        Node* idx = root;
        for(int i = 0; i<word.size(); i++) {
            int target = word[i] - 'a';
            if(!idx->next[target]) return false;
            idx = idx->next[target];
        }
        return idx->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.length()==0) return root->isWord;
        Node* idx = root;
        for(int i = 0; i<prefix.size(); i++) {
            int target = prefix[i] - 'a';
            if(!idx->next[target]) return false;
            idx = idx->next[target];
        }
        return idx;
        if(idx->isWord) return true;
        for(auto i:idx->next) if(i) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
