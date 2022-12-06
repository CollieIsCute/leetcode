#include <iostream>
using namespace std;

// Definition for singly-linked list.
//  struct ListNode {
//  	int val;
//  	ListNode* next;
//  	ListNode() : val(0), next(nullptr) {}
//  	ListNode(int x) : val(x), next(nullptr) {}
//  	ListNode(int x, ListNode* next) : val(x), next(next) {}
//  };

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode *even = nullptr, *cur = head, *even_last = nullptr;
		while(cur && cur->next) {
			if(!even_last) {
				even_last = cur->next;
				if(!even)
					even = even_last;
			}
			else {
				even_last->next = cur->next;
				even_last = even_last->next;
			}
			cur->next = cur->next->next;
			if(cur->next)
				cur = cur->next;
		}
		if(even_last)
			even_last->next = nullptr;
		if(cur)
			cur->next = even;
		return head;
	}
};