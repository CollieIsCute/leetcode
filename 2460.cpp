#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> applyOperations(vector<int>& nums) {
		const int Size = nums.size();
		for(int i = 0; i < nums.size() - 1;) {
			if(nums[i] == 0) {
				nums.erase(nums.begin() + i);
			}
			else if(nums[i] == nums[i + 1]) {
				nums[i] += nums[i + 1];
				nums.erase(nums.begin() + i + 1);
				++i;
			}
			else
				++i;
		}
		nums.resize(Size);
		return nums;
	}
};