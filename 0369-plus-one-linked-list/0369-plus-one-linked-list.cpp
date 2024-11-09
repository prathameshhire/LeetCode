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
    int helper(ListNode* temp) {
        if (!temp) return 1;
        int carry = helper(temp->next);
        temp->val = temp->val + carry;
        if (temp->val < 10) {
            return 0;
        }
        temp->val = 0;
        return 1;
    }

    ListNode* plusOne(ListNode* head) {
        int carry = helper(head);
        if (carry) {
            ListNode* newHead = new ListNode (1,head);
            return newHead;
        }
        return head;
    }
};