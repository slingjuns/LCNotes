# 143. Reorder List

Careful: Yes
Date: October 6, 2023
Difficulty: Medium
Elegant Code (Template): Two Pointers
Index: 143
Programming Language: C++
Skills: 1. 一道题集合了reverse list + find middle node + merge two list
Tags: Two Pointers
Link: https://leetcode.com/problems/reorder-list/

## 注意

- **reverse 后 1→2→3→4会变成 1→2→3,  nullptr←←3←4**
- 需要在最后把第一个数组2→ 变为2→nullptr

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
         // range is [left, right)
         while(cur != right) {
             auto tmp = cur->next;
             cur->next = prev;
             prev = cur;
             cur = tmp;
         }
         return prev;
     }
    
    void reorderList(ListNode* head) {
        // find the middle
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // reverse 
        ListNode* l1 = head, *l2 = reverse(slow, nullptr);
        // merge two list, be careful of handling even list
        // 1->2->3 null<-3<-4
        while(l1 && l2) {
            auto tmp_l1 = l1->next, tmp_l2 = l2->next;
            l1->next = l2;
            l2->next = tmp_l1;            
            l1 = tmp_l1;
            l2 = tmp_l2;
        }
        if(l1) l1->next = nullptr;
    }
};
```