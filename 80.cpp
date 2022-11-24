#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		bool has_two = false;
		for(int i = 0; i < nums.size() - 1; i++) {
			if(nums[i] == nums[i + 1]) {
				if(has_two) {
					nums.erase(nums.begin() + i + 1);
					i--;
				}
				has_two = true;
			}
			else
				has_two = false;
		}
		return nums.size();
	}
};