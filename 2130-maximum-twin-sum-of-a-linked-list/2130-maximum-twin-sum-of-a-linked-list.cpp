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
    int pairSum(ListNode* head) {
        vector<int> list;
        while(head != NULL) {
            list.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = list.size()-1;
        int result = INT_MIN;
        while (i < j) {
            result = max(result, list[i] + list[j]);
            i++;
            j--;
        }
        return result;
    }
};