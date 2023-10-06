// Date: October 6, 2023
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
