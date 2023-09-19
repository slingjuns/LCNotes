# 208. Implement Trie (Prefix Tree)

Careful: No
Date: September 19, 2023
Difficulty: Medium
Elegant Code (Template): Trie
Index: 208
Programming Language: C++
Tags: Trie
Link: https://leetcode.com/problems/implement-trie-prefix-tree/

```cpp
class Trie {
typedef struct TreeNode {
    int value;
    TreeNode* nodes[26];
    TreeNode() {
        value = 0;
        for(int i = 0; i < 26; ++i) nodes[i] = nullptr;
    }
} TreeNode;
TreeNode* root;
public:
    Trie() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* cur = root;
        for(int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if(!cur->nodes[ch-'a']) cur->nodes[ch-'a'] = new TreeNode();
            cur = cur->nodes[ch-'a'];
        }
        cur->value += 1;
    }
    
    bool search(string word) {
        TreeNode* cur = root;
        for(int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if(!cur->nodes[ch-'a']) return false;
            cur = cur->nodes[ch-'a'];
        }
        return cur->value > 0;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        for(int i = 0; i < prefix.length(); ++i) {
            char ch = prefix[i];
            if(!cur->nodes[ch-'a']) return false;
            cur = cur->nodes[ch-'a'];
        }
        return cur != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```