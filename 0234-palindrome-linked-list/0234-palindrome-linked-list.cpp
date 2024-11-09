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
    bool isPalindrome(ListNode* head) {
        stack <int> st;
        ListNode* temp = head;
        while(temp) {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            int value = st.top();
            if (temp->val != value) {
                return false;
            }  
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};