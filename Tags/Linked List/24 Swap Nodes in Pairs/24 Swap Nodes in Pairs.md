# 24. Swap Nodes in Pairs

Careful: Yes
Date: September 24, 2022
Difficulty: Medium
Index: 24
Programming Language: C++
Skills: 1. Recursion in Linkedlist
Tags: Linked List
Link: https://leetcode.com/problems/swap-nodes-in-pairs/

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return dfs(head);
    }
    
    ListNode* dfs(ListNode* head) { // post-order traversal
        if (!head) return nullptr;
        if (head->next) {
            auto right = head->next;
            head->next = dfs(right->next);
            right->next = head;
            return right;
        }
        return head;
    }
};
```