// Date: October 3, 2022
class Solution {
unordered_map<Node*, Node*> m;
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1);
        Node* curr = head, *l2_curr = dummy;
        while(curr) {
            if(!m.count(curr)) m[curr] = new Node(curr->val);
            l2_curr->next = m[curr];
            if(!m.count(curr->random) && curr->random) m[curr->random] = new Node(curr->random->val);
            l2_curr->next->random = m[curr->random];
            l2_curr = l2_curr->next;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
