
// Definition for singly-linked list.
// struct ListNode {
// 	int val;
// 	ListNode *next;
// 	ListNode() : val(0), next(nullptr) {}
// 	ListNode(int x) : val(x), next(nullptr) {}
// 	ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode *fast = head, *slow = head;
    for (bool slow_turn = true; fast->next; slow_turn = !slow_turn) {
      fast = fast->next;
      slow = slow_turn ? slow->next : slow;
    }
    return slow;
  }
};