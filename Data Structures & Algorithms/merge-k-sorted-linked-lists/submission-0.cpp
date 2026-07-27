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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (ListNode* l : lists) {
            pq.push({l->val, l});
        }
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;

        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            node->next = p.second;
            node = node->next;
            if (p.second->next) pq.push({p.second->next->val, p.second->next});
        }
        return dummy->next;
        
    }
};
