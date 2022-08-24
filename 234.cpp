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

#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	list<int> list = convert_to_vector(head), rev_list(list);
	rev_list.reverse();
	for(auto it1 = list.begin(), it2 = rev_list.begin(); it1 != list.end(); it1++, it2++){
	    if(*it1 != *it2)
		return false;
	}
	return true;
    }

    list<int> convert_to_vector(ListNode* head){
	list<int> ret;
	while(head){
	    ret.push_back(head->val);
	    head = head->next;
	}
	return ret;
    }

};
