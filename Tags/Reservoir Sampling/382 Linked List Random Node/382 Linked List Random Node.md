# 382. Linked List Random Node

Careful: No
Date: October 8, 2023
Difficulty: Medium
Elegant Code (Template): Reservoir Sampling
Index: 382
Programming Language: C++
Skills: 经典蓄水池抽样
Tags: Reservoir Sampling
Link: https://leetcode.com/problems/linked-list-random-node/

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
ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int m = 1;
        ListNode* chosen = nullptr, *cur = head;
        int count = 1;
        while(cur) {
            int val = rand() % count;
            if(val == 0) chosen = cur;
            count++;
            cur = cur->next;
        }
        return chosen->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```