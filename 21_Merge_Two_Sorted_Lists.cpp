/**
 * Definition for singly-linked list.
 * */
//  struct ListNode {
// 	int val;
// 	ListNode* next;
// 	ListNode() : val(0), next(nullptr) {}
// 	ListNode(int x) : val(x), next(nullptr) {}
// 	ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode **min = nullptr, *ret = nullptr, *cur = nullptr;
		if(!list1)
			return list2;
		if(!list2)
			return list1;
		while(list1 and list2) {
			min = list1->val < list2->val ? &list1 : &list2;
			if(ret == nullptr)
				ret = cur = *min;
			else {
				cur->next = *min;
				cur = cur->next;
			}
			*min = (*min)->next;
		}
		cur->next = list1 ? list1 : list2;
		return ret;
	}
};