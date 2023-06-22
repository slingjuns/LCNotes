// Date: June 22, 2023
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 找每一部分的head 和非null tail节点
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = dummy;
        for(int i = 0; i < left-1; ++i) {
            curr = curr->next;
        } // 第一部分尾节点
        ListNode *first_tail = curr;
        cout << first_tail->val << endl;
        
        ListNode *reverse_start = curr->next; // 第二部分头节点
        curr = reverse_start;
        for(int i = 0; i < right-left; ++i) {
            curr = curr->next;
        }
        ListNode *reverse_end = curr->next; // 第三部分头节点
        ListNode *reversedHead = reverseBetween(reverse_start, reverse_end);
        first_tail->next = reversedHead;
        return dummy->next;
    }
    
    ListNode* reverseBetween(ListNode* left, ListNode* right) { // [a, b)
        ListNode *pre = right, *cur = left;
        while (cur != right) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        return pre;
    }
};
