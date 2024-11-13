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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; 
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge2ll(ListNode* right, ListNode* left) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        while (right && left) {
            if (right->val < left->val) {
                temp->next = right;
                temp = right;
                right = right->next;
            }
            else{
                temp->next = left;
                temp = left;
                left = left->next;
            }
            if (right) temp->next = right;
            else temp->next = left;
        }
        return dummyHead->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge2ll (right, left);
    }
};