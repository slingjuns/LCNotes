# 138. Copy List with Random Pointer

Careful: No
Date: October 3, 2022
Difficulty: Medium
Index: 138
Programming Language: C++
Skills: 1. Use Hash Map to store pointers
Tags: Hash Table, Linked List
Link: https://leetcode.com/problems/copy-list-with-random-pointer/

```cpp
class Solution {
unordered_map<Node*, Node*> m;
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1);
        Node* curr = head, *l2_curr = dummy;
        while(curr) {
            if(!m.count(curr)) m[curr] = new Node(curr->val);
            l2_curr->next = m[curr];
            if(!m.count(curr->random) && curr->random) m[curr->random] = new Node(curr->random->val);
            l2_curr->next->random = m[curr->random];
            l2_curr = l2_curr->next;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
```