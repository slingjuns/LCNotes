# 19. Remove Nth Node From End of List

Careful: Yes
Date: October 5, 2022
Difficulty: Medium
Elegant Code (Template): Fast Slow Pointer, Two Pointers
Index: 19
Programming Language: C++
Skills: 1. 控制快慢指针间距为k  (需要fast指针先走k个距离, 之后按同样速度走)
Tags: Fast Slow Pointer, Two Pointers
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        auto slow = dummy, fast = dummy;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
```