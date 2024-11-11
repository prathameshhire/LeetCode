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

    ListNode* findKth(ListNode* temp, int k) {
        k--;
        while (temp && k) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head) {
        if (!head->next || !head) return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while (temp) {
            ListNode* kthNode = findKth (temp, k);
            if (!kthNode) {
                if (prevNode) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if (temp == head) head = kthNode;
            else prevNode->next = kthNode;
            prevNode = temp;
            temp = nextNode; 
        }
        return head;
    }
};