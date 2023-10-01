# 237. Delete Node in a Linked List

Careful: No
Date: October 1, 2023
Difficulty: Medium
Index: 237
Programming Language: C++
Tags: Linked List
Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```