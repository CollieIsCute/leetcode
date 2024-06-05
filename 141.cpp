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
    bool hasCycle(ListNode* head) {
        while (head) {
            if (head->val == 10e4 + 1)
                return true;
            head->val = 10e4 + 1;
            head = head->next;
        }
        return false;
    }
};
