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
