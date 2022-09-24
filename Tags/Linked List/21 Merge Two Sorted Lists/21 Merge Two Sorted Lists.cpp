// Date: September 24, 2022
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto l1 = list1, l2 = list2;
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        while (l1 && l2) {
            auto val1 = l1->val, val2 = l2->val;
            if (val1 < val2) {
                res->next = l1;
                l1 = l1->next;
            }
            else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if (l1) res->next = l1;
        else res->next = l2;
        return dummy -> next;
    }
};
