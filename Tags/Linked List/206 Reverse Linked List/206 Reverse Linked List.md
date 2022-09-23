# 206. Reverse Linked List

Careful: No
Date: September 23, 2022
Difficulty: Easy
Index: 206
Programming Language: C++
Skills: 1. Reverse the linkedlist in place
Tags: Linked List
Link: https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        // inplace
        auto cur = head;
        ListNode* newHead = nullptr;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        return newHead;
    }
};
```