# 430. Flatten a Multilevel Doubly Linked List

Careful: Yes
Date: October 1, 2023
Difficulty: Medium
Elegant Code (Template): DFS, Linked List
Index: 430
Programming Language: C++
Tags: DFS, Linked List
Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

```cpp
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
```