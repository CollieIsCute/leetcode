#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for(int zero = 0, not_zero = 0;
			zero < nums.size() && not_zero < nums.size();) {
			if(nums[zero] != 0)
				++zero;
			else if(nums[not_zero] == 0)
				++not_zero;
			else if(not_zero > zero)
				swap(nums[zero], nums[not_zero]);
			else
				++not_zero;
		}
	}
};