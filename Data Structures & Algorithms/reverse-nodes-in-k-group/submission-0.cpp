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
    pair<ListNode*, ListNode*> reverse_list(ListNode* node, int k) {
        ListNode* curr = node;
        ListNode* prev = nullptr;
        ListNode* temp;
        pair<ListNode*, ListNode*> result;
        while (curr && k) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            k--;
        }
        result.first = node;
        result.second = prev;
        return result;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr;
        ListNode* next = head;

        while (next) {
            int c = 1;
            while (c <= k && next) {
                if (c == 1) curr = next;
                next = next->next;
                c++;
            }
            if (c - 1 < k) return dummy->next;
            pair<ListNode*, ListNode*> p = reverse_list(curr, k);
            prev->next = p.second;
            p.first->next = next;
            prev = p.first;
        }


        return dummy->next;
        
    }
};
