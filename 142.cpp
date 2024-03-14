
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

#include <set>
using namespace std;

class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    set<ListNode*> record;
    ListNode* beg = [&]() {
      for (ListNode* cur = head; cur; cur = cur->next) {
        if (record.find(cur) != record.end())
          return cur;
        else
          record.insert(cur);
      }
      return static_cast<ListNode*>(nullptr);
    }();
    return beg;
  }
};