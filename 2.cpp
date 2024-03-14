/**
 * I did a trick. "if l1 or l2 ends, then ret list use the other one's last node
 * as return list.
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ret = nullptr, *now = nullptr, *prev = nullptr;
    while (l1 != nullptr && l2 != nullptr) {
      now = new ListNode(l1->val + l2->val);
      prev ? prev->next = now : 0;
      ret == nullptr ? ret = now : 0;
      prev = now;
      l1 = l1->next;
      l2 = l2->next;
    }

    // only one list not end, or both end.
    l1 == nullptr ? prev->next = l2 : prev->next = l1;

    checkCarry(ret);
    return ret;
  }

  void checkCarry(ListNode* l) {
    ListNode *now = l, *prev = nullptr;
    int carry = 0;
    while (now) {
      now->val += carry;
      carry = now->val / 10;
      now->val %= 10;
      prev = now;
      now = now->next;
    }
    while (carry) {
      now = new ListNode(carry % 10);
      prev->next = now;
      carry /= 10;
      prev = now;
      now = now->next;
    }
  }
};