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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* before = head;
        ListNode* after = head->next;
        int a, b, c;
        while (after) {
            int c = gcd(before->val, after->val);
            ListNode* curr = new ListNode(c, after);
            before->next = curr;

            before = after;
            after = after->next;
        }
        return head;
    }

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};