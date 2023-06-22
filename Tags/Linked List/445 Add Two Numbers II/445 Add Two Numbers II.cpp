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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        auto r1 = reverse(l1), r2 = reverse(l2);
        // add
        bool add10 = false;
        auto curr_r1 = r1, curr_r2 = r2, curr=dummy;
        while(curr_r1 || curr_r2) {
            int res = 0;
            if(curr_r1) {
                res += curr_r1->val;
                curr_r1 = curr_r1->next;
            }
            if(curr_r2) {
                res += curr_r2->val;
                curr_r2 = curr_r2->next;
            }
            res += add10;
            int digit = res % 10;
            add10 = res >= 10 ? true : false;
            curr->next = new ListNode(digit);
            curr = curr->next;
        }
        if(add10) curr->next = new ListNode(1);
        return reverse(dummy->next);
    }
    
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    
};
