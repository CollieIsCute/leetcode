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

struct ListNode; // for auto-completion

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
		ListNode **indirect_del = &head, *trav_p = head;
		for(bool go_next = 0; trav_p; trav_p = trav_p->next, go_next = !go_next)
			indirect_del = go_next ? &(*indirect_del)->next : indirect_del;
		*indirect_del = (*indirect_del)->next;
		return head;
	}
};