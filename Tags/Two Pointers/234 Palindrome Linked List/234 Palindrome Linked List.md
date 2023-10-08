# 234. Palindrome Linked List

Careful: Yes
Date: October 8, 2023
Difficulty: Easy
Index: 234
Programming Language: C++
Skills: 1. 找middle node + reverse linkedlist + traverse
Tags: Linked List, Two Pointers
Link: https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode* reverse(ListNode* left, ListNode* right) {
        ListNode* prev = nullptr, *cur = left;
        while(cur != right) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse
        auto newHead = reverse(slow, nullptr);
        
        // match
        ListNode* l1 = newHead, *l2 = head;
        while(l1 && l2) {
            if(l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
};
```