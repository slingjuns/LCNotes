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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue
        auto comp = [&](ListNode *a, ListNode *b) {
            return a->val > b->val; // min_heap
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp); // only non-null pointers exist
        
        for (ListNode* h: lists) { // only store k Node
            if (h) pq.push(h);
        }
        ListNode *dummy = new ListNode();
        auto cur = dummy;
        while (!pq.empty()) { // O(Nlog(k))
            auto c = pq.top();
            pq.pop();
            cur -> next = c;  
            cur = cur->next;
            if (c->next) pq.push(c->next);
        }
        return dummy->next;
    }
};
