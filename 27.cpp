#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, const int val) {
		for(auto iter = nums.begin(); iter != nums.end(); iter++) {
			if(*iter == val) {
				iter = nums.erase(iter);
				iter--;
			}
		}
		return nums.size();
	}
};