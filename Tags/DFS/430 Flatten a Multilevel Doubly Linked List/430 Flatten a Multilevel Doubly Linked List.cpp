// Date: October 1, 2023
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node* prev, Node* curr) {
        if(!curr) return prev;
        prev->next = curr;
        curr->prev = prev;
        // return tail of the list
        auto tmpChild = curr->child;
        auto tmpNext = curr->next;
        curr->child = nullptr;
        // first recurse on child
        auto tail = dfs(curr, tmpChild);
        return dfs(tail, tmpNext);
    }
    
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node* dummy = new Node;
        dfs(dummy, head);
        dummy->next->prev = nullptr;
        return dummy->next;
    }
};
