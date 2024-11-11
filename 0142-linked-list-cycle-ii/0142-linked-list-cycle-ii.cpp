/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    #define Node ListNode
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow!=fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            } 
        }
        return NULL;   
    }
};