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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(5,head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                curr = prev->next;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};