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
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        int v1, v2;
        while (l1 || l2 || carry) {
            l1 ? v1 = l1->val : v1 = 0;
            l2 ? v2 = l2->val : v2 = 0;
            int val = v1 + v2 + carry;
            carry = val / 10;
            val = val % 10;
            ListNode* newNode = new ListNode(val);
            cur->next = newNode;
            cur = cur->next;
            l1 ? l1 = l1->next : nullptr;
            l2 ? l2 = l2->next : nullptr;
        }
        return dummy->next; 
    }
};