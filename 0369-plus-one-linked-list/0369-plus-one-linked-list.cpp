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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        ListNode* temp = head;
        int carry = 1;
        while (temp) {
            temp->val = temp->val + carry;
            if (temp->val < 10) {
                carry = 0;
                break;
            } else {
                carry = 1;
                temp->val = 0;
            }
            temp = temp->next;
        }
        if (carry == 1) {
            head = reverse(head);
            ListNode* newHead = new ListNode(1, head);
            return newHead;
        }
        head = reverse(head);
        return head;
    }
};